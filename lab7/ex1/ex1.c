#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int cnt;

unsigned long x=0;



void* inc_thread(void* n){
    fprintf(stdout,"Thread inc created!\n");
    for(int i=0;i<*((int*)n);i++)
        x+=1;
    return NULL;
}

void* dec_thread(void* n){
    fprintf(stdout,"Thread dec created!\n");
    for(int i=0;i<*((int*)n);i++)
        x-=1;
    return NULL;
}

void thread_pull(int n_thr,int n){
    pthread_t threads[n_thr*2];
    pthread_attr_t thr_attr;
    pthread_attr_init(&thr_attr);
    pthread_attr_setdetachstate(&thr_attr,PTHREAD_CREATE_JOINABLE);
    for(int i=0;i<n_thr*2;i+=1){
        if(i%2==0)
            pthread_create(&threads[i],&thr_attr,&inc_thread,&n);
        else
            pthread_create(&threads[i],&thr_attr,&dec_thread,&n);
    }
    for(int i=0;i<n_thr*2;i++)
        pthread_join(threads[i],NULL);
    return;
}


int main(int argc,char** argv){
    int n_thr=3,n=2;
    char opt;
    while((opt=getopt(argc,argv,"n:t:"))!=-1){
        switch(opt){
            case 'n':
                n=atoi(optarg); cnt = n;
                break;
            case 't':
                n_thr=atoi(optarg);
                break;
            default:
                fprintf(stdout,"Error: invalid argument!\n");
                break;
        }
    }
    fprintf(stdout,"N=%d T=%d\n",n,n_thr);
    for(int i=0;i<cnt;i++){
        thread_pull(n_thr,n);
        fprintf(stdout,"X=%lu\n",x);
        usleep(1000);
    }
    return 0;
}
