#include <stdio.h>
int main()
{
    int light;
    // Here 1=Red Light, 2= Yellow Light, 3= Green Light
    printf("Entr Any Number:");
    scanf("%d", &light);
    if (light == 1)
    {
        printf("Stop It is Red light.");
    }
    else if (light == 2)
    {
        printf("Ready It is a Yellow Light.");
    }
    else if (light == 3)
    {
        printf("Go! It is a Green Light.");
    }
    else
    {
        printf("Invalid Input");
    }

return 0;
}