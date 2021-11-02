#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

char* buff=NULL;

void func(void){
  printf("Wait 3 seconds...\n");
  sleep(3);
  system("clear");
  free(buff);
}

void info(){
  printf("Usage: my_cmd [-h] [-b]\n-h //help message\n-b //buffer size\n");
}

int main(int argc,char** argv){
  const struct option long_opt[]={
      {"help",0,0,'h'},
      {"buffer",1,0,'b'}
  };
  int cmd;
  int buff_size=127;
  
  while((cmd=getopt_long(argc,argv,"hb:",long_opt,NULL))!=-1){
    switch(cmd){
      case 'h':
        info();
        return 0;
      case 'b':
        buff_size=atoi(optarg);
        break;
    }
  }
  buff =(char*)malloc(sizeof(char)*buff_size);
  if(atexit(func))printf("Error in reg. func\n");
  char* login;
  while(1){
    login =getlogin();
    printf("%s$:",login);
    
    fgets(buff,buff_size,stdin);
    if(!strcmp(buff,"stop\n"))break;
    system(buff);
  }
  return 0;

}
