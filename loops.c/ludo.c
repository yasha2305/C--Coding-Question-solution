#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define FINISH 57
#define CELL 36
#define BX 25
#define BY 75

typedef struct {
    int row, col;
} Cell;

typedef struct {
    int progress[N][N];
    int start[N];
    int lane[N][5][2];
    int home[N][N][2];
    Color color[N];
    const char *name[N];
} Game;

const Cell track[52] = {
    {6,1},{6,2},{6,3},{6,4},{6,5},
    {5,6},{4,6},{3,6},{2,6},{1,6},{0,6},
    {0,7},{0,8},
    {1,8},{2,8},{3,8},{4,8},{5,8},
    {6,9},{6,10},{6,11},{6,12},{6,13},{6,14},
    {7,14},{8,14},
    {8,13},{8,12},{8,11},{8,10},{8,9},
    {9,8},{10,8},{11,8},{12,8},{13,8},{14,8},
    {14,7},{14,6},
    {13,6},{12,6},{11,6},{10,6},{9,6},
    {8,5},{8,4},{8,3},{8,2},{8,1},{8,0},
    {7,0},{6,0}
};

Color colors[N] = {
    {30, 170, 85, 255},    // Green
    {45, 115, 235, 255},   // Blue
    {245, 195, 35, 255},   // Yellow
    {225, 55, 65, 255}     // Red
};

const char *names[N] = {
    "GREEN", "BLUE", "YELLOW", "RED"
};

int starts[N] = {0, 13, 26, 39};

int safeSquares[] = {0, 8, 13, 21, 26, 34, 39, 47};

Vector2 centerOf(int row, int col) {
    return (Vector2){
        BX + col * CELL + CELL / 2.0f,
        BY + row * CELL + CELL / 2.0f
    };
}

void drawCell(int row, int col, Color color) {
    DrawRectangle(BX + col * CELL, BY + row * CELL,
                  CELL, CELL, color);
    DrawRectangleLines(BX + col * CELL, BY + row * CELL,
                       CELL, CELL, (Color){195, 200, 205, 255});
}

void drawHome(int row, int col, Color color) {
    DrawRectangle(BX + col * CELL, BY + row * CELL,
                  6 * CELL, 6 * CELL, color);
    DrawRectangle(BX + col * CELL + 9,
                  BY + row * CELL + 9,
                  6 * CELL - 18, 6 * CELL - 18, RAYWHITE);
    DrawRectangleLines(BX + col * CELL + 9,
                       BY + row * CELL + 9,
                       6 * CELL - 18, 6 * CELL - 18, color);
}

void drawBoard(Game *g) {
    // Board background
    DrawRectangle(BX - 3, BY - 3, 15 * CELL + 6,
                  15 * CELL + 6, DARKGRAY);

    DrawRectangle(BX, BY, 15 * CELL, 15 * CELL,
                  (Color){248, 249, 250, 255});

    // Four home areas
    drawHome(0, 0, g->color[0]);
    drawHome(0, 9, g->color[1]);
    drawHome(9, 9, g->color[2]);
    drawHome(9, 0, g->color[3]);

    // Main track
    for (int i = 0; i < 52; i++) {
        int r = track[i].row;
        int c = track[i].col;

        drawCell(r, c, (Color){255, 255, 255, 255});

        // Highlight each player's starting square
        for (int p = 0; p < N; p++) {
            if (i == g->start[p])
                drawCell(r, c, g->color[p]);
        }
    }

    // Colored home lanes
    for (int i = 0; i < 5; i++) {
        drawCell(1 + i, 7, g->color[0]);
        drawCell(7, 13 - i, g->color[1]);
        drawCell(13 - i, 7, g->color[2]);
        drawCell(7, 1 + i, g->color[3]);
    }

    // Center finishing area
    int cx = BX + 6 * CELL;
    int cy = BY + 6 * CELL;

    DrawRectangle(cx, cy, 3 * CELL, 3 * CELL, RAYWHITE);
    DrawTriangle(
        (Vector2){cx, cy},
        (Vector2){cx + 3 * CELL, cy},
        (Vector2){cx + 1.5f * CELL, cy + 1.5f * CELL},
        g->color[0]
    );
    DrawTriangle(
        (Vector2){cx + 3 * CELL, cy},
        (Vector2){cx + 3 * CELL, cy + 3 * CELL},
        (Vector2){cx + 1.5f * CELL, cy + 1.5f * CELL},
        g->color[1]
    );
    DrawTriangle(
        (Vector2){cx + 3 * CELL, cy + 3 * CELL},
        (Vector2){cx, cy + 3 * CELL},
        (Vector2){cx + 1.5f * CELL, cy + 1.5f * CELL},
        g->color[2]
    );
    DrawTriangle(
        (Vector2){cx, cy + 3 * CELL},
        (Vector2){cx, cy},
        (Vector2){cx + 1.5f * CELL, cy + 1.5f * CELL},
        g->color[3]
    );

    // Safe squares
    for (int i = 0; i < 8; i++) {
        int idx = safeSquares[i];
        Vector2 pos = centerOf(track[idx].row, track[idx].col);
        DrawCircleV(pos, 5, (Color){40, 40, 40, 255});
    }
}

Vector2 tokenPosition(Game *g, int p, int t) {
    int progress = g->progress[p][t];

    // Tokens waiting at home
    if (progress == 0) {
        return centerOf(g->home[p][t][0],
                        g->home[p][t][1]);
    }

    // Tokens in the final home lane
    if (progress >= 52 && progress <= 56) {
        int r = g->lane[p][progress - 52][0];
        int c = g->lane[p][progress - 52][1];
        return centerOf(r, c);
    }

    // Token has reached the center
    if (progress == FINISH) {
        return centerOf(7, 7);
    }

    // Tokens moving on the main track
    int idx = (g->start[p] + progress - 1) % 52;
    return centerOf(track[idx].row, track[idx].col);
}

void drawTokens(Game *g, int current, int selected) {
    for (int p = 0; p < N; p++) {
        for (int t = 0; t < N; t++) {
            Vector2 pos = tokenPosition(g, p, t);

            // Separate tokens sharing the same square slightly
            int same = 0;
            for (int pp = 0; pp <= p; pp++) {
                for (int tt = 0; tt < N; tt++) {
                    if (pp == p && tt >= t) break;
                    if (g->progress[pp][tt] == g->progress[p][t] &&
                        g->progress[p][t] != 0 &&
                        g->progress[p][t] != FINISH &&
                        Vector2Distance(
                            tokenPosition(g, pp, tt), pos) < 1.0f) {
                        same++;
                    }
                }
            }

            if (same > 0 && g->progress[p][t] != 0 &&
                g->progress[p][t] != FINISH) {
                pos.x += (same % 2 ? -6 : 6);
                pos.y += (same < 2 ? -5 : 5);
            }

            float radius = (p == current && t == selected) ? 13 : 10;

            DrawCircleV((Vector2){pos.x + 1, pos.y + 2},
                        radius, (Color){60, 60, 60, 90});
            DrawCircleV(pos, radius, g->color[p]);
            DrawCircleLines((int)pos.x, (int)pos.y,
                            radius, RAYWHITE);
            DrawCircle((int)(pos.x - 3), (int)(pos.y - 3),
                       3, (Color){255, 255, 255, 190});

            if (g->progress[p][t] == FINISH) {
                DrawText("X", (int)pos.x - 5,
                         (int)pos.y - 7, 14, BLACK);
            }
        }
    }
}

int trackIndex(Game *g, int p, int progress) {
    if (progress < 1 || progress > 51) return -1;
    return (g->start[p] + progress - 1) % 52;
}

int isSafe(int index) {
    for (int i = 0; i < 8; i++) {
        if (safeSquares[i] == index) return 1;
    }
    return 0;
}

int canMove(Game *g, int p, int t, int dice) {
    int pos = g->progress[p][t];

    if (pos == FINISH) return 0;
    if (pos == 0) return dice == 6;
    return pos + dice <= FINISH;
}

int anyMoves(Game *g, int p, int dice) {
    for (int t = 0; t < N; t++) {
        if (canMove(g, p, t, dice)) return 1;
    }
    return 0;
}

void moveToken(Game *g, int p, int t, int dice) {
    if (!canMove(g, p, t, dice)) return;

    if (g->progress[p][t] == 0) {
        g->progress[p][t] = 1;
    } else {
        g->progress[p][t] += dice;
    }

    int idx = trackIndex(g, p, g->progress[p][t]);

    // Capture opponents on non-safe main-track squares
    if (idx >= 0 && !isSafe(idx)) {
        for (int op = 0; op < N; op++) {
            if (op == p) continue;

            for (int ot = 0; ot < N; ot++) {
                int otherIdx = trackIndex(
                    g, op, g->progress[op][ot]);

                if (otherIdx == idx) {
                    g->progress[op][ot] = 0;
                }
            }
        }
    }
}

int playerWon(Game *g, int p) {
    for (int t = 0; t < N; t++) {
        if (g->progress[p][t] != FINISH) return 0;
    }
    return 1;
}

int tokenClicked(Game *g, int p, int mx, int my) {
    for (int t = N - 1; t >= 0; t--) {
        Vector2 pos = tokenPosition(g, p, t);

        if (CheckCollisionPointCircle(
                (Vector2){(float)mx, (float)my}, pos, 15)) {
            return t;
        }
    }
    return -1;
}

void initGame(Game *g) {
    for (int p = 0; p < N; p++) {
        g->start[p] = starts[p];
        g->color[p] = colors[p];
        g->name[p] = names[p];

        for (int t = 0; t < N; t++) {
            g->progress[p][t] = 0;
        }
    }

    // Green: top-left
    int homeSpots[N][N][2] = {
        {{2,2},{2,4},{4,2},{4,4}},
        {{2,11},{2,13},{4,11},{4,13}},
        {{10,11},{10,13},{12,11},{12,13}},
        {{10,2},{10,4},{12,2},{12,4}}
    };

    // Green lane, Blue lane, Yellow lane, Red lane
    int lanes[N][5][2] = {
        {{1,7},{2,7},{3,7},{4,7},{5,7}},
        {{7,13},{7,12},{7,11},{7,10},{7,9}},
        {{13,7},{12,7},{11,7},{10,7},{9,7}},
        {{7,1},{7,2},{7,3},{7,4},{7,5}}
    };

    for (int p = 0; p < N; p++) {
        for (int t = 0; t < N; t++) {
            g->home[p][t][0] = homeSpots[p][t][0];
            g->home[p][t][1] = homeSpots[p][t][1];
        }

        for (int i = 0; i < 5; i++) {
            g->lane[p][i][0] = lanes[p][i][0];
            g->lane[p][i][1] = lanes[p][i][1];
        }
    }
}

int main(void) {
    Game game;
    initGame(&game);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1000, 700, "LUDO GAME - C / Raylib");
    SetTargetFPS(60);
    srand((unsigned int)time(NULL));

    int current = 0;
    int dice = 0;
    int rolled = 0;
    int winner = -1;
    int selected = -1;
    int mustPass = 0;
    int extraTurn = 0;
    const char *message = "Click ROLL DICE to begin!";

    Rectangle rollButton = {650, 250, 250, 58};
    Rectangle passButton = {650, 330, 250, 50};

    while (!WindowShouldClose()) {
        int mx = GetMouseX();
        int my = GetMouseY();

        if (winner == -1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(
                    (Vector2){(float)mx, (float)my}, rollButton)) {

                if (!rolled && !mustPass) {
                    dice = rand() % 6 + 1;
                    rolled = 1;
                    selected = -1;
                    extraTurn = (dice == 6);

                    if (!anyMoves(&game, current, dice)) {
                        message = "No valid moves! Pass your turn.";
                        mustPass = 1;
                    } else {
                        message = "Click one of your movable tokens.";
                    }
                }
            } else if (mustPass &&
                       CheckCollisionPointRec(
                           (Vector2){(float)mx, (float)my}, passButton)) {
                current = (current + 1) % N;
                rolled = 0;
                mustPass = 0;
                dice = 0;
                message = "Your turn! Roll the dice.";
            } else if (rolled && !mustPass) {
                int t = tokenClicked(&game, current, mx, my);

                if (t >= 0 && canMove(&game, current, t, dice)) {
                    int old = game.progress[current][t];
                    moveToken(&game, current, t, dice);

                    if (old == 0) {
                        message = "Token entered the board!";
                    } else {
                        message = "Token moved!";
                    }

                    if (playerWon(&game, current)) {
                        winner = current;
                        message = "Congratulations! You won!";
                    } else if (!extraTurn) {
                        current = (current + 1) % N;
                    } else {
                        message = "You rolled a 6! Roll again.";
                    }

                    rolled = 0;
                    dice = 0;
                    selected = -1;
                } else {
                    message = "Invalid token. Choose a highlighted move.";
                }
            }
        }

        BeginDrawing();
        ClearBackground((Color){240, 243, 247, 255});

        DrawText("LUDO", 650, 35, 38, (Color){35, 45, 60, 255});
        DrawText("CLASSIC BOARD GAME", 653, 78, 17, GRAY);

        drawBoard(&game);
        drawTokens(&game, current, selected);

        // Right-side information panel
        DrawRectangleRounded(
            (Rectangle){630, 115, 340, 525},
            0.06f, 12, RAYWHITE);

        DrawText("CURRENT PLAYER", 655, 135, 16, GRAY);
        DrawCircle(665, 180, 12, game.color[current]);
        DrawText(game.name[current], 690, 165, 27,
                 (Color){35, 45, 60, 255});

        DrawText("DICE", 655, 215, 17, GRAY);

        DrawRectangleRounded(
            (Rectangle){655, 235, 75, 75},
            0.15f, 8, WHITE);
        DrawRectangleRoundedLines(
            (Rectangle){655, 235, 75, 75},
            0.15f, 8, 2, LIGHTGRAY);

        if (dice == 0) {
            DrawText("?", 678, 249, 44, DARKGRAY);
        } else {
            char d[2] = {(char)('0' + dice), '\0'};
            DrawText(d, 678, 249, 44, BLACK);
        }

        DrawRectangleRounded(rollButton, 0.2f, 10,
                             (rolled || mustPass) ? GRAY :
                             (Color){35, 150, 85, 255});
        DrawText("ROLL DICE", 696, 269, 20, WHITE);

        if (mustPass) {
            DrawRectangleRounded(passButton, 0.2f, 10,
                                 (Color){225, 145, 35, 255});
            DrawText("NEXT PLAYER", 700, 345, 20, WHITE);
        }

        DrawText("TOKENS FINISHED", 655, 405, 16, GRAY);
        for (int p = 0; p < N; p++) {
            int finished = 0;
            for (int t = 0; t < N; t++) {
                if (game.progress[p][t] == FINISH) finished++;
            }

            DrawCircle(665, 443 + p * 35, 8, game.color[p]);

            char line[80];
            snprintf(line, sizeof(line), "%s: %d / 4",
                     game.name[p], finished);
            DrawText(line, 685, 432 + p * 35, 19, DARKGRAY);
        }

        DrawText("GAME MESSAGE", 655, 585, 16, GRAY);
        DrawText(message, 655, 608, 15, DARKGRAY);

        if (winner >= 0) {
            DrawRectangle(0, 0, GetScreenWidth(),
                          GetScreenHeight(),
                          (Color){0, 0, 0, 150});

            DrawRectangleRounded(
                (Rectangle){250, 250, 500, 180},
                0.12f, 12, RAYWHITE);

            DrawText("GAME OVER!", 385, 275, 35, GOLD);
            DrawText(TextFormat("%s WINS!", game.name[winner]),
                     365, 330, 30, game.color[winner]);
            DrawText("Close the window to exit.",
                     365, 385, 18, DARKGRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}