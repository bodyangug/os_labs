#include "main.h"


int main(int argc,char** argv){
    const struct option long_opt[]={
        {"pid",0,0,'P'},//0
        {"ppid",0,0,'p'},//1
        {"grp",0,0,'g'},//2
        {"uid",0,0,'u'},//3
        {"euid",0,0,'U'},//4
        {"gid",0,0,'i'},//5
        {"egid",0,0,'I'},//6
        {"all",0,0,'a'}
    };
    if(argc<2){
        print_help();
        return 0;
    }
    
    system_function functions[7]={mgetpid,mgetppid,mgetpgrp,mgetuid,mgeteuid,mgetgid,mgetegid};
    
    int cmd;
    unsigned char cmd_byte=0;
    while((cmd=getopt_long(argc,argv,"PpguUiIa",long_opt,NULL))!=-1){
        switch(cmd){
            case 'P':
                cmd_byte|=1;
                break;
            case 'p':
                cmd_byte|=(1<<1);
                break;
            case 'g':
                cmd_byte|=(1<<2);
                break;
            case 'u':
                cmd_byte|=(1<<3);
                break;
            case 'U':
                cmd_byte|=(1<<4);
                break;
            case 'i':
                cmd_byte|=(1<<5);
                break;
            case 'I':
                cmd_byte|=(1<<6);
                break;
            case 'a':
                cmd_byte|=0x7f;
        }
    }
    char buf[1024];
    memset(buf,0,sizeof(buf));
    int pos=0;
    for(int i=0;i<7;i++){
        if((cmd_byte&(1<<i))!=0){
            pos+=functions[i](buf+pos);
        }
    }
    fprintf(stdout,"%s",buf);
    return 0;
}

int mgetpid(char* buf){
    pid_t t=getpid();
    //buf[0]='H';
    return sprintf(buf,"Pid: 0x%x\n",t);
}
int mgetppid(char* buf){
    pid_t t=getppid();
    return sprintf(buf,"Ppid: 0x%x\n",t);
}
int mgetpgrp(char* buf){
    pid_t t=getpgrp();
    return sprintf(buf,"PGrp: 0x%x\n",t);    
}
int mgetuid(char* buf){
    pid_t t=getuid();
    return sprintf(buf,"Uid: 0x%x\n",t); 
}
int mgeteuid(char* buf){
    pid_t t=geteuid();
    return sprintf(buf,"Euid: 0x%x\n",t); 
}
int mgetgid(char* buf){
    pid_t t=getgid();
    return sprintf(buf,"Gid: 0x%x\n",t); 
}
int mgetegid(char* buf){
    pid_t t=getegid();
    return sprintf(buf,"Egid: 0x%x\n",t); 
}

void print_help(){
    fprintf(stdout,"Usage: pi [--pid] [--ppid] [--grp] [--uid] [--euid] [--gid] [--egid] [--all]\n");
}

 
