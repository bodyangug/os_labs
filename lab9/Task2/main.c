#include "stdio.h"
#include "signal.h"
#include "unistd.h"
#include "stdlib.h"

char* text;

void handler(int signo){
	printf("%s\n", text);
	exit(0);
}



int main(int argc, char** argv){
	if(argc<3)return 0;
	text = *(argv+2);
	int time = atoi(*(argv+1));
	printf("text:%s time:%d\n", text, time);
	if (fork() == 0) {
		alarm(time);
		signal(SIGALRM, handler);
		pause();
	} else {
		printf("triger set \n");
	}
	return 0;
}
