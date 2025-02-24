#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int myRandom(int max)
{
    int x;
    x = rand() % max + 1;

    return x;
}

int main() 
{
    int balance, bet, guess, dice;

    srand(getpid());

    balance = 1000;
    printf("make your bet: ");
    fflush(stdout);
    scanf("%d", &bet);

    printf("make your guess (1-6, or 0 to exit): \n");
    scanf("%d", &guess);
    if (guess ==0)
    {
        return 0;
    }
    sleep(2);
    dice = myRandom(6);
    printf("%d\n", dice);

    return 0;
}