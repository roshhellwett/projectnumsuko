#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define delay(ms) Sleep(ms)
#else
#include <unistd.h>
#define delay(ms) usleep((ms) * 1000)
#endif

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

typedef struct {
    int gamesPlayed;
    int gamesWon;
    int gamesLost;
    int currentStreak;
    int bestStreak;
    int totalScore;
} Stats;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[1;1H");
#endif
}

void printBanner() {
    clearScreen();
    printf(BOLD CYAN);
    printf("\n");
    printf("  _______  _               _   _                 _ _ _ \n");
    printf(" |__   __|| |             | | | |               | | | |\n");
    printf("    | |   | |__   ___     | |_| | __ _ _   _  __| | | |\n");
    printf("    | |   | '_ \\ / _ \\    |  _  |/ _` | | | |/ _` | | |\n");
    printf("    | |   | | | |  __/    | | | | (_| | |_| | (_| | |_|\n");
    printf("    |_|   |_| |_|\\___|    |_| |_|\\__,_|\\__,_|\\__,_|_(_)\n");
    printf("\n");
    printf("              " BOLD YELLOW "~ A Number Guessing Game ~" RESET "\n");
    printf(BOLD MAGENTA "                    By: ROSHHELLWETT\n" RESET);
    printf("\n");
}

void printBox(const char* title) {
    int len = strlen(title);
    printf(BOLD BLUE "╔");
    for (int i = 0; i < len + 2; i++) printf("═");
    printf("╗\n");
    printf("║ " BOLD CYAN "%s" RESET BLUE " ║\n", title);
    printf("╚");
    for (int i = 0; i < len + 2; i++) printf("═");
    printf("╝\n" RESET);
}

void printStats(Stats* stats) {
    printf(BOLD YELLOW "\n═══════════════════════════════════════\n");
    printf("           📊 GAME STATISTICS 📊\n");
    printf("═══════════════════════════════════════\n" RESET);
    printf("  🎮  Games Played : " BOLD "%d\n" RESET, stats->gamesPlayed);
    printf("  ✅  Games Won    : " GREEN "%d\n" RESET, stats->gamesWon);
    printf("  ❌  Games Lost   : " RED "%d\n" RESET, stats->gamesLost);
    printf("  🔥 Current Streak: " YELLOW "%d\n" RESET, stats->currentStreak);
    printf("  ⭐  Best Streak   : " GREEN "%d\n" RESET, stats->bestStreak);
    printf("  🏆  Total Score   : " CYAN "%d\n" RESET, stats->totalScore);
    if (stats->gamesPlayed > 0) {
        float winRate = (float)stats->gamesWon / stats->gamesPlayed * 100;
        printf("  📈  Win Rate      : " BOLD "%.1f%%\n" RESET, winRate);
    }
    printf(BOLD YELLOW "═══════════════════════════════════════\n" RESET);
}

void celebratoryAnimation() {
    printf("\n");
    const char* colors[] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN};
    for (int round = 0; round < 2; round++) {
        for (int i = 0; i < 6; i++) {
            printf("%s★ ", colors[i]);
            fflush(stdout);
            delay(100);
        }
    }
    printf(RESET "\n");
}

void printMenu() {
    printf(BOLD "\n");
    printf("  ╔═══════════════════════════════╗\n");
    printf("  ║      🎯 SELECT DIFFICULTY     ║\n");
    printf("  ╠═══════════════════════════════╣\n");
    printf("  ║  " GREEN "1." RESET " EASY   → 1-10, 5 chances   ║\n");
    printf("  ║  " YELLOW "2." RESET " MEDIUM → 1-20, 10 chances  ║\n");
    printf("  ║  " RED "3." RESET " HARD   → 1-100, 10 chances  ║\n");
    printf("  ║  " CYAN "4." RESET " SHOW STATISTICS         ║\n");
    printf("  ║  " MAGENTA "5." RESET " QUIT GAME              ║\n");
    printf("  ╚═══════════════════════════════╝\n" RESET);
    printf(BOLD CYAN "\n  Enter your choice: " RESET);
}

int getValidInput(int* choice) {
    char input[10];
    if (scanf("%s", input) != 1) return 0;
    
    for (int i = 0; input[i]; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
    }
    *choice = atoi(input);
    return 1;
}

void giveHint(int guess, int target, int attempt, int maxAttempts) {
    if (attempt < 2 || maxAttempts - attempt < 2) return;
    
    int diff = abs(guess - target);
    
    printf(BOLD);
    if (diff <= 3) {
        printf(YELLOW "  🔥 BURNING HOT! " RESET);
    } else if (diff <= 7) {
        printf(CYAN "  ♨️  WARM " RESET);
    } else if (diff <= 15) {
        printf(BLUE "  ❄️  COLD " RESET);
    } else {
        printf(RED "  🥶 FREEZING! " RESET);
    }
    
    if (target % 2 == 0) {
        printf(YELLOW "(Hint: Target is EVEN)\n" RESET);
    } else {
        printf(YELLOW "(Hint: Target is ODD)\n" RESET);
    }
    printf("\n");
}

int main() {
    Stats stats = {0, 0, 0, 0, 0, 0};
    int guess, chances, choose, max, min, random_number;
    char choice;
    
    srand(time(NULL));
    
    printBanner();
    printf(BOLD GREEN "  Welcome to NUMSUKO! 🎲\n" RESET);
    printf("  Can you guess the secret number?\n");
    delay(1500);
    
    do {
        printBanner();
        printMenu();
        
        if (!getValidInput(&choose)) {
            printf(RED "\n  ⚠️  Invalid input! Please enter a number.\n" RESET);
            delay(1000);
            continue;
        }
        
        if (choose == 5) {
            printBanner();
            printf(BOLD GREEN "\n  Thanks for playing! Farewell, challenger!\n\n" RESET);
            if (stats.gamesPlayed > 0) {
                printStats(&stats);
            }
            printf(BOLD CYAN "\n  Final Score: %d\n", stats.totalScore);
            printf("  Come back soon! 👋\n\n" RESET);
            break;
        }
        
        if (choose == 4) {
            printBanner();
            printStats(&stats);
            printf(BOLD "\n  Press Enter to continue..." RESET);
            getchar();
            getchar();
            continue;
        }
        
        if (choose < 1 || choose > 5) {
            printf(RED "\n  ⚠️  Invalid choice! Please select 1-5.\n" RESET);
            delay(1000);
            continue;
        }
        
        switch (choose) {
            case 1:
                min = 1; max = 10; chances = 5;
                break;
            case 2:
                min = 1; max = 20; chances = 10;
                break;
            case 3:
                min = 1; max = 100; chances = 10;
                break;
        }
        
        random_number = min + rand() % (max - min + 1);
        
        printBanner();
        printf(BOLD GREEN "\n  🎮 NEW GAME STARTED!\n" RESET);
        printf("  Guess the number between " CYAN "%d" RESET " and " CYAN "%d" RESET "\n", min, max);
        printf("  You have " YELLOW "%d" RESET " chances - Good luck!\n\n", chances);
        
        int won = 0;
        
        for (int i = 0; i < chances; i++) {
            printf(BOLD CYAN "  Attempt %d/%d - Your guess: " RESET, i + 1, chances);
            
            if (scanf("%d", &guess) != 1) {
                printf(RED "  ⚠️  Invalid input! Please enter a number.\n" RESET);
                getchar();
                i--;
                continue;
            }
            
            if (guess < min || guess > max) {
                printf(RED "  ⚠️  Out of range! Enter between %d and %d\n" RESET, min, max);
                i--;
                continue;
            }
            
            if (guess == random_number) {
                printBanner();
                printf(GREEN "\n");
                printf("  ╔═══════════════════════════════╗\n");
                printf("  ║     🎉 CONGRATULATIONS! 🎉     ║\n");
                printf("  ║    You guessed it right!      ║\n");
                printf("  ╚═══════════════════════════════╝\n" RESET);
                
                celebratoryAnimation();
                
                int baseScore = 100;
                int difficultyMultiplier = choose;
                int remainingBonus = (chances - i - 1) * 20;
                int roundScore = (baseScore * difficultyMultiplier) + remainingBonus;
                
                stats.totalScore += roundScore;
                stats.gamesWon++;
                stats.currentStreak++;
                if (stats.currentStreak > stats.bestStreak) {
                    stats.bestStreak = stats.currentStreak;
                }
                
                printf(BOLD YELLOW "\n  +%d points!\n" RESET, roundScore);
                printf("  Remaining chances: %d\n", chances - i - 1);
                won = 1;
                break;
            }
            else if (guess < random_number) {
                printf(RED "  📉 Too LOW! Try higher!\n" RESET);
            }
            else {
                printf(RED "  📈 Too HIGH! Try lower!\n" RESET);
            }
            
            giveHint(guess, random_number, i, chances);
            printf(BOLD "  Chances left: " YELLOW "%d\n" RESET, chances - i - 1);
            printf("\n");
        }
        
        if (!won) {
            printBanner();
            printf(RED "\n");
            printf("  ╔═══════════════════════════════╗\n");
            printf("  ║      😢 GAME OVER! 😢        ║\n");
            printf("  ╚═══════════════════════════════╝\n" RESET);
            printf("\n");
            printf(BOLD "  The secret number was: " GREEN "%d\n\n" RESET, random_number);
            
            stats.gamesLost++;
            stats.currentStreak = 0;
        }
        
        stats.gamesPlayed++;
        
        printStats(&stats);
        
        printf(BOLD "\n  Play again? " CYAN "(y/n)" RESET ": ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
    
    printBanner();
    printf(BOLD GREEN "\n  Thank you for playing NUMSUKO!\n" RESET);
    printf("  Your final score: " YELLOW "%d\n\n" RESET, stats.totalScore);
    
    return 0;
}
