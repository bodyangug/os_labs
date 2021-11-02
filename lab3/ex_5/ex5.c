#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(int argc,char** argv){
  int cmd,n=0;
  char buff[20];
  const struct option long_opt[]={
    {"file",1,0,'f'},
    {"number",1,0,'n'}
  };
  while((cmd=getopt_long(argc,argv,"f:n:",long_opt,NULL))!=-1){
    switch(cmd){
      case 'f':
        if(setenv("FILE_NAME",optarg,1)==-1)
          printf("Was error\n");
        break;
      case 'n':
        n=atoi(optarg);
        break;
    }
  }
  printf("n=%d\n",n);
  for(int i=1;i<n+1;i++){
    int pid=fork();
    if(pid==0){
      printf("New thread!\n");
      sprintf(&buff,"%d",i);
      sleep(2);
      if(execl("./child","./child",&buff,NULL)==-1)printf("%s\n",strerror(errno));
      break;
    }
  }
  return 0;
}
