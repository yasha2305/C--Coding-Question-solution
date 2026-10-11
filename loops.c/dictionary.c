
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Word {
    char word[30];
    char meaning[200];
};

int main() {
    struct Word dictionary[] = {
        {"apple", "A fruit that is usually red or green."},
        {"book", "A set of written or printed pages."},
        {"computer", "An electronic device that processes data."},
        {"programming", "The process of writing computer instructions."},
        {"python", "A popular high-level programming language."},
        {"beautiful", "Having qualities that give pleasure."},
        {"brave", "Ready to face danger or difficulty."},
        {"education", "The process of learning and gaining knowledge."},
        {"friend", "A person whom you know and trust."},
        {"happy", "Feeling pleasure or joy."},
        {"honest", "Always telling the truth."},
        {"knowledge", "Information and skills gained through learning."},
        {"love", "A strong feeling of affection."},
        {"nature", "The physical world, including plants and animals."},
        {"success", "The achievement of a goal."},
        {"technology", "The use of scientific knowledge for practical purposes."},
        {"water", "A clear liquid essential for life."},
        {"computer", "An electronic machine used to process information."},
        {"science", "The systematic study of the natural world."},
        {"discipline", "The practice of following rules and controlling behavior."}
    };

    int n = sizeof(dictionary) / sizeof(dictionary[0]);
    char search[30];
    int found, i, j;

    printf("====================================\n");
    printf("       WELCOME TO DICTIONARY        \n");
    printf("====================================\n");

    while (1) {
        printf("\nEnter a word (type exit to quit): ");
        scanf("%29s", search);

        for (i = 0; search[i] != '\0'; i++) {
            search[i] = tolower((unsigned char)search[i]);
        }

        if (strcmp(search, "exit") == 0) {
            printf("Thank you for using the dictionary!\n");
            break;
        }

        found = 0;

        for (j = 0; j < n; j++) {
            if (strcmp(search, dictionary[j].word) == 0) {
                printf("\nWord: %s\n", dictionary[j].word);
                printf("Meaning: %s\n", dictionary[j].meaning);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Sorry, this word is not in the dictionary.\n");
        }
    }

    return 0;
}