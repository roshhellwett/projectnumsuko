#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n----CREATED BY ROSHHELLWETT----\n");
    int guess, chances, choose, max, min, random_number;
    char choice;

    srand(time(NULL)); // Seed only once

    do
    {
        printf("\nCHOOSE YOUR LEVEL\n");
        printf("1. EASY (1 TO 10, 5 chances)\n");
        printf("2. MEDIUM (1 TO 20, 10 chances)\n");
        printf("3. HARD (1 TO 100, 10 chances)\n");
        printf("4. QUIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choose);

        if (choose == 4)
        {
            printf("GOODBYE!\n");
            break;
        }

        switch (choose)
        {
            case 1:
                min = 1; max = 10; chances = 5;
                break;
            case 2:
                min = 1; max = 20; chances = 10;
                break;
            case 3:
                min = 1; max = 100; chances = 10;
                break;
            default:
                printf("INVALID CHOICE TRY AGAIN \n");
                continue;
        }

        random_number = min + rand() % (max - min + 1);

        for (int i = 0; i < chances; i++)
        {
            printf("\nGUESS A NUMBER BETWEEN %d AND %d: ", min, max);
            scanf("%d", &guess);

            if (guess == random_number)
            {
                printf(":-) CONGRATULATIONS YOU GUESSED IT !\n");
                break;
            }
            else if (guess < random_number)
            {
                printf("TOO LOW !\n");
            }
            else
            {
                printf("TOO HIGH !\n");
            }

            printf("CHANCES LEFT : %d\n", chances - i - 1);
        }

        if (guess != random_number)
            printf("\n :-( OUT OF CHANCES ! THE CORRECT NUMBER WAS %d.\n", random_number);

        printf("\nDO YOU WANT TO PLAY AGAIN ? (y/n): ");
        scanf(" %c", &choice);

    }
    while (choice == 'y' || choice == 'Y');

    printf("THANKS FOR PLAYING !\n");
    return 0;
}

