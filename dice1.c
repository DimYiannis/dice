#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int myRandom(int max)
{
    int x;
    /* create a random number between 1 and max*/
    x = rand() % max + 1;

    return x;
}

int main()
{
    int balance, bet, guess, dice;

    // seeding the random number generator
    srand(getpid());

    balance = 1000;

    while (1)
    {
        printf("make your bet: ");
        // forces immediate output.
        fflush(stdout);
        scanf("%d", &bet);

        printf("make your guess (1-6, or 0 to exit): \n");
        scanf("%d", &guess);
        //user presses 0 in order to quit
        if (guess == 0)
        {
            return 0;
        }

        printf("throwing the dice... \n");
        //suspends execution for a specified number of seconds
        sleep(2);
        dice = myRandom(6);
        printf("dice result: %d\n", dice);

        if (guess != dice)
        {
            balance = balance - bet;
            printf("you lost! \n");
        }
        else
        {
            bet *= 3;
            balance += bet;
            printf("you won congratulations!! \n ");
        }

        if (balance == 0)
        {
            printf("game over\n");
            return 0;
        }

        printf("balance : $%d\n", balance);
    }

    return 0;
}