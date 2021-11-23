#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void handler_a(int signo, siginfo_t *si, void *ucontext){
	printf("Recived: %d\n",(int)si->si_int);
}
int main(){
	int child = fork();
	if (child == 0) {

		struct sigaction sa;
		sa.sa_sigaction = handler_a;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);

		sleep(1);
		while(1){
			pause();
		}
	} else {
		union sigval value;
		sleep(1);
		for(int i = 0; i < 15; i++){
			value.sival_int = i;
			sigqueue(child, SIGUSR1, value);
			kill(child, SIGUSR1);
			sleep(1);
		}
	}
	return 0;
}
