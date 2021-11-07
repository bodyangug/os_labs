#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char** argv){
    time_t now =time(NULL);
    pid_t pid =fork();
    unsigned long cnt=0;
    while((time(NULL)-now)<5)cnt++;
    if(pid==0)fprintf(stdout,"Child process cnt:  %lu\n",cnt);
    else if(pid>0)fprintf(stdout,"Parent process cnd: %lu\n",cnt);
    else fprintf(stdout,"Error: can`t create process!\n");
}
