#include <stdio.h>
#include <stdlib.h>

void func(int status,void* arg){
  printf("%s\n",arg);
  free(arg);
  sleep(1);
}


int main(int argc,char** argv){
  if(argc<2)
    return 1;
  int n= atoi(argv[1]);
  for(int i=0;i<n;i++){
    char* str=(char*)malloc(sizeof(char)*n);
    sprintf(str,"function number %d",i);
    if(on_exit(func,(void*)str))printf("Can't register %d function\n",i);
  }
  return 0;
}
