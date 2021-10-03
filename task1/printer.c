#include <stdio.h>

int printResult(int win)
{
    if (win > 0)
    {
        for (size_t i = 0 ;i < 5; i++)
        {
            printf("WIN!\n");
        }
    }
    printf("You win: %d$\n",win);
 
    return 0;
}