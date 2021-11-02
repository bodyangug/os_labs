#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float my_random (float a, float b) 
{
    float y;
    int x;
    x = rand(); 
    y = a + (x * (b - a)) / RAND_MAX; 
    return y;
}

int main(int argc,char** argv){
  srand(time(NULL));
  if(argc<2)return -1;
  int n=atoi(argv[1]);
  char file_name[128];
  char* prefix = getenv("FILE_NAME");
  if(prefix!=NULL)strcpy(&file_name,prefix);
  else strcpy(&file_name,"/home/bohdan/Documents/test/");
  char file[128];
  sprintf(file,"%sfile%d",file_name,n);
  printf("%s\n",file);
  FILE* f = fopen(file,"w");
  for(int i=0;i<n;i++){
    float data =my_random(0,1);
    fprintf(f,"%f ",data);
  }
  fclose(f);
  return 0;
}
