#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "lab2.h"

extern char **environ;
extern char  *optarg;

int main(int argc,char** argv){
  const struct option long_opt[]={
    {"help",0,0,'h'},
    {"info",1,0,'i'},
    {"set",1,0,'s'},
    {"assign",1,0,'a'},
    {"value",2,0,'v'},
    {"del",1,0,'d'},
    {"clear",0,0,'c'}
  };
  if(argc<2){
    print_current_env();
    return 0;
  }
  
  int cmd;
  char buff_value[256];
  char buff_name[256];
  unsigned char flag=0;
  while((cmd=getopt_long(argc,argv,"hi:s:a:v:d:c",long_opt,NULL))!=-1){
    
    switch(cmd){
      case 'h':
        print_info("environ");
        break;
      case 'i':
        print_variable(optarg);
        break;
      case 's':
        set_variable(optarg);
        break;
      case 'a':
       // printf("%d %c\n",(char)cmd,cmd);
        strcpy(buff_name,optarg);
        flag|=0xF0;
        break;
      case 'v':
       //   printf("%d %c\n",(char)cmd,cmd);
        strcpy(buff_value,optarg);
        flag|=0x0F;
        break;
      case 'd':
        del_variable(optarg);
        print_current_env();
        break;
      case 'c':
        clear_env();
        print_current_env();
        break;
    }
  }
  //printf("flag=%x",flag);
  if(flag==0xFF){
   if(setenv(&buff_name,&buff_value,1)==-1){
    printf("Was error\n");
  }else  printf("All set!\n");
  print_variable(&buff_name);   
  }
  return 0;
}


void print_current_env(void){
  char** ptr=environ;
  if(ptr==NULL)printf("Environment is clear!\n");
  else
  while(*ptr!=NULL){
    printf("%s\n",*ptr);
    ptr++;
  }
}

void print_info(char* name){
  printf("Usage: %s\n--help -h  = print help\n--info -i [var name]  = print variable\n",name);
}


void print_variable(char *name){
  char* var = getenv(name);
  if(var==NULL)printf("Variable not found\n"); 
  else printf("%s=%s\n",name,var);
}

void set_variable(char* name){
   // printf("%s\n",name);
  char var_name[255];
  char var_value[255];
  char* dest_ptr=&var_name,*src_ptr=name;
  while(src_ptr[0]!='='){
    if(src_ptr[0]==0){
      printf("Error: invalid parametr --info\n");
      print_info("environ");
      return;
    }
   
    dest_ptr[0]= src_ptr[0];
    dest_ptr++;src_ptr++;
  }
  dest_ptr[0]=0;
  
  dest_ptr=&var_value;
  src_ptr++;
  strcpy(dest_ptr,src_ptr);
  // printf("%s\n",var_name);
  if(setenv(&var_name,&var_value,1)==-1){
    printf("Was error\n");
  }
  print_variable(&var_name);
}

void del_variable(char* name){
  if(unsetenv(name)==-1){
    printf("Error when del variable\n");
  }
}

void clear_env(){
  clearenv();
}
