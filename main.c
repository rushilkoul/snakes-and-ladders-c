#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int rollDie() { return rand() % 6 + 1; }

void printHorizontalSeparator()
{
    printf("---------------------------------------------------------------------------------\n");
}

int player1 = 0;
int player2 = 0;

void printVerticalSeparators()
{
    printf("|\n");
    for (int i = 1; i < 12; i++)
    {
        printf("|\t");
    }
    printf("\n");

}

void printBoard()
{
    int board[101];
    for (int i = 1; i <= 100; i++) {
        board[i] = i;
    }

    int total = 100;
    int alternate = 0;
    int iteratorLR = 101;
    int iteratorRL = 80;
    printHorizontalSeparator();
    while (total--)
    {
        if(alternate == 0)
        {
            iteratorLR--;
            printf("|");
            
            printf("%d", board[iteratorLR]);
            if (player1 == board[iteratorLR])
                printf(ANSI_COLOR_CYAN"P1"ANSI_COLOR_RESET);

            if(player2 == board[iteratorLR])
                printf(ANSI_COLOR_YELLOW"P2"ANSI_COLOR_RESET);
            printf("\t");
            
            if (iteratorLR % 10 == 1)
            {
                printVerticalSeparators();
                alternate = 1;
                iteratorLR -= 10;
                printHorizontalSeparator();
            }
        }
        else
        {
            iteratorRL++;
            printf("|");
            printf("%d", board[iteratorRL]);
            
            if (player1 == board[iteratorRL])
                printf(ANSI_COLOR_CYAN"P1"ANSI_COLOR_RESET);
            
            if(player2 == board[iteratorRL])
                printf(ANSI_COLOR_YELLOW"P2"ANSI_COLOR_RESET);
            
            printf("\t");

            if (iteratorRL % 10 == 0)
            {
                printVerticalSeparators();
                alternate = 0;
                iteratorRL -= 30;
                printHorizontalSeparator();
            }
        }
        
    }
    printf("\n");
}

void setPlayerState(int player, int _player)
{
    // player can be 1 or 2, _player is the local position to be updated globally.
    if(player == 1)
        player1 = _player;
    else
        player2 = _player;
}

void gameLogic(int chance)
{
    
    int _player;
    if(chance == 1)
        _player = player1;
    else
        _player = player2;

    while(1)
    {
        printBoard();
        printf("Player %d's Turn\n(press enter to roll):\n", chance);
        scanf("%c");
        int rolled = rollDie();
        printf("Player %d Rolled a ", chance);
        printf(ANSI_COLOR_RED"%d\n"ANSI_COLOR_RESET,rolled);
    
        if(_player + rolled > 100)
        {
            // cant move
        }
        else
        {
            _player += rolled;
            if(_player == 100)
            {
                // player won
            }
            // snakes and ladders detection
        }
        setPlayerState(chance, _player);
        if(rolled != 6)
            break;
        printf(ANSI_COLOR_GREEN"ROLL AGAIN!\n"ANSI_COLOR_RESET);

    }
}

int main()
{
    int chance = 1;
    

    srand(time(NULL)); //random seed
    printf("Welcome to Snakes and Ladders.\n");
    while(1)
    {
        gameLogic(chance);
        if(chance == 1)
            chance = 2;
        else
            chance = 1;
    }
    return 0;

    // printf("-----------------------------\n");
    // printf("WELCOME TO SNAKES AND LADDERS\n");
    // printf("-----------------------------\n");
    
    // int dummy;
    // int player1 = 0;
    // int player2 = 0;
    // int diceRoll;

    // int chance = 0;

    // int gameOver = 0;

    // int snakes[3][2] = 
    // {
    //     {11,5}, {20,6}, {55,4}
    // };
    // while (gameOver != 1)
    // {
    //     printf("Player 1 Position: %d\tPlayer 2 Position: %d\n\n", player1, player2);
    //     printf("\tPlayer %d's chance. Press enter to roll:", chance + 1);
    //     getchar();
    //     diceRoll = (rand() % 6) + 1;
    //     printf("\nPlayer %d Rolled a %d\n\n", chance + 1, diceRoll);

    //     if (chance == 0)
    //     {
    //         for (int i = 0; i <= sizeof(snakes) / sizeof(snakes[0]); i++)
    //         {
    //             if(player1 == snakes[i][0])
    //             {
    //                 printf("%d------\n", snakes[i][0]);
    //             }
    //         }
    //         player1 += diceRoll;
    //         chance = 1;
    //     }
    //     else 
    //     {
    //         player2 += diceRoll;
    //         chance = 0;
    //     }

    // }

}