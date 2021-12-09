#include <sys/types.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int fd1, fd2;
    int N = 100;
    char resstring[N], ch;
    int i;
    size_t size;
    char name1[]="fd1.fifo";
 
    unlink(name1);


    (void)umask(0);

    if(mknod(name1,S_IFIFO |0666,0)<0){
        printf("can't create fifo\n");
        exit(-1);
    }

    if((fd1 = open(name1, O_RDWR)) < 0){
            printf("Can\'t open FIFO for reading/writing\n");
            exit(-1);
}
    

    while(1){
    printf("vvedite stroku\n");
 
    fgets(resstring,N,stdin);
    
    
    
    i = 0;
    while (resstring[i]){
        ch=resstring[i];
      
        resstring[i] = putchar(toupper(ch));
        i++;
    }    
 
        size = write(fd1, resstring, N);
        if(size < 0){
        printf("Can\'t write string\n");
        exit(-1);
    }
    

        size = read(fd1, resstring, N);
        if(size < 0){
        printf("Can\'t read string\n");
        exit(-1);
    }
}
}