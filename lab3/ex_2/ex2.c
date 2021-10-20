#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
  char buf[128];
  while(1){
    fgets(buf,128,stdin);
    printf("%s",buf);
    int res=system(buf);
    if(res==127 || res==-1)
      printf("can't process comand\n");
  }
  return 0;
}
