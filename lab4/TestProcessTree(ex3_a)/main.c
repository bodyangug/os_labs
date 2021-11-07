#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


int main(int argc,char** argv){
    int cnt=0;
    
    pid_t pid1=fork();
    if(pid1==0){
        cnt++;
        
        pid_t pid2=fork();
        
        if(pid2==0){
            cnt++;
            printf("Process 4 cnt: 0x%x cnt_addr: 0x%x\n",cnt,&cnt);
            fprintf(stdout,"Process 4 pid: 0x%x ppid: 0x%x\n",getpid(),getppid());
        }else if(pid2>0){
            printf("Process 2 cnt: 0x%x cnt_addr: 0x%x\n",cnt,&cnt);
            fprintf(stdout,"Process 2 pid: 0x%x ppid: 0x%x\n",getpid(),getppid());
        }
    }else if(pid1>0){
        pid_t pid2=fork();
        if(pid2==0){
            cnt++;
            printf("Process 3 cnt: 0x%x cnt_addr: 0x%x\n",cnt,&cnt);
            fprintf(stdout,"Process 3 pid: 0x%x ppid: 0x%x\n",getpid(),getppid());
        }else if(pid2>0){
            printf("Process 1 cnt: 0x%x cnt_addr: 0x%x\n",cnt,&cnt);
            fprintf(stdout,"Process 1 pid: 0x%x ppid: 0x%x\n",getpid(),getppid());
        }
    }
    return 0;
}
