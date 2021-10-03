#include <stdio.h>

int main()
{
    oneHandBandit();
    return 0;
}

int oneHandBandit()
{
     srand(time(0));
    while(1){
     int bid = writeBid();
     if(bid == 0){
         printf("Bye!!\n");
         break;
     }
     printf("Your bid is : %d$\n", bid);
     
     int rand = generateRandomNumber();
     printf("Your random number: %d\n", rand);
     
     int win = proccesWin(bid,rand);
     printResult(win);
    }
    return 0;
}


int generateRandomNumber()
{
    return (rand() %(999 - 100 + 1)) + 100;
}

int proccesWin(int bid,int rand)
{
     char buf[BUFSIZ];
     sprintf(buf, "%d", rand);
     
    if (buf[0] == '7' && buf[1] == '7' && buf[2] == '7')
     {
         return bid * 3;
     }
    if (buf[0] == buf[1] && buf[1] == buf[2])
    {
        return bid *2;
    }
    if (buf[0] == '7' || buf [1] == '7' || buf[2] == '7')
    {
        return bid;
    }
    if(buf[0] == buf[1] || buf[0] == buf[2] || buf[1] == buf[2])
    {
        return bid;
    }
    return 0;
}
