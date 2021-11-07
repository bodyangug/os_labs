#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <wait.h>

pid_t* pids;

int main(int argc,char** argv){
    if(argc<2)return 0;
    double radius;
    int thr_cnt,retval=0;
    float status=0;
    int n=atoi(argv[1]);
    pids=(pid_t*)malloc(sizeof(pid_t)*n);
    pid_t pid = getpid();
    for(int i=0;i<n;i++){
        
        pid_t pid_child = fork();
        if(pid_child==0){
            execlp("./child","./child",argv[1],NULL);
           // system("./child 10");
            fprintf(stdout,"Error!\n");
        }else if(pid_child==pid)return 0;
        sleep(1);
    }
    for(int i=0;i<n;i++){
        waitpid(pids[i],&retval,0);
      //  fprintf(stdout,"retval %d\n",WEXITSTATUS(retval));
        if(retval!=-1)status+= WEXITSTATUS(retval);
        else fprintf(stdout,"Something wrong!\n");
    }
    status/=n;
    free(pids);
    fprintf(stdout,"Pi = %f %f",status,(status)/(n)*4);
    return 0;
}



