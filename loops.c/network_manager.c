#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#pragma comment(lib, "ws2_32.lib")

#define MAX_HOSTS 10

int check_website(const char *host)
{
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    struct hostent *he;
    DWORD start, end;
    int result;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return -1;

    he = gethostbyname(host);

    if (he == NULL)
    {
        WSACleanup();
        return -1;
    }

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock == INVALID_SOCKET)
    {
        WSACleanup();
        return -1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(443);
    memcpy(&server.sin_addr, he->h_addr_list[0], he->h_length);

    u_long mode = 1;
    ioctlsocket(sock, FIONBIO, &mode);

    start = GetTickCount();

    result = connect(sock, (struct sockaddr *)&server, sizeof(server));

    if (result == SOCKET_ERROR)
    {
        fd_set writefds;
        fd_set exceptfds;
        struct timeval timeout;

        FD_ZERO(&writefds);
        FD_ZERO(&exceptfds);
        FD_SET(sock, &writefds);
        FD_SET(sock, &exceptfds);

        timeout.tv_sec = 3;
        timeout.tv_usec = 0;

        result = select(0, NULL, &writefds, &exceptfds, &timeout);

        if (result <= 0 || FD_ISSET(sock, &exceptfds))
        {
            closesocket(sock);
            WSACleanup();
            return -1;
        }

        int error = 0;
        int len = sizeof(error);

        getsockopt(sock, SOL_SOCKET, SO_ERROR,
                   (char *)&error, &len);

        if (error != 0)
        {
            closesocket(sock);
            WSACleanup();
            return -1;
        }
    }

    end = GetTickCount();

    closesocket(sock);
    WSACleanup();

    return (int)(end - start);
}

int main(void)
{
    const char *websites[] = {
        "google.com",
        "github.com",
        "python.org",
        "microsoft.com",
        "wikipedia.org"
    };

    int count = sizeof(websites) / sizeof(websites[0]);
    int choice;

    while (1)
    {
        printf("\n=================================\n");
        printf("       NETWORK MONITOR\n");
        printf("=================================\n");
        printf("1. Check all websites\n");
        printf("2. Check one website\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            return 1;
        }

        if (choice == 1)
        {
            printf("\nChecking websites...\n\n");

            for (int i = 0; i < count; i++)
            {
                int time_ms = check_website(websites[i]);

                if (time_ms >= 0)
                {
                    printf("%-20s ONLINE  | %d ms\n",
                           websites[i], time_ms);
                }
                else
                {
                    printf("%-20s OFFLINE | Connection failed\n",
                           websites[i]);
                }
            }
        }
        else if (choice == 2)
        {
            char host[256];

            printf("Enter hostname (example: example.com): ");
            scanf("%255s", host);

            int time_ms = check_website(host);

            if (time_ms >= 0)
                printf("%s is reachable in %d ms\n", host, time_ms);
            else
                printf("Could not connect to %s\n", host);
        }
        else if (choice == 3)
        {
            printf("Exiting Network Monitor. Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
