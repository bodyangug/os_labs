#include <stdlib.h>
#include <getopt.h>
#include <pthread.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
extern char **environ;

pthread_rwlock_t mx=PTHREAD_RWLOCK_INITIALIZER;
int *arr=NULL;
int count_el=10;

void controller(void * arg){
	for (int i = 0; i < 100; ++i){
		printf("Controller: ");
		for (int i = 0; i < count_el; i++)
			printf("arr[%i]=%i ",i, *(arr+i));
		printf("\n");
		printf("Controller sleep\n");
		sleep(1);
	}
	printf("Controller exit\n");
}

void reader(void *arg){
	srand(time(NULL)+pthread_self());
	for (int i = 0; i < 20; ++i){
		int rand_var=rand()%10;
		int rand_number_cell=rand()%*(int*)arg;
		pthread_rwlock_rdlock(&mx);
		printf("reader %li read cell %i number in cell %i\n",pthread_self(),rand_number_cell,*(arr+rand_number_cell));
		pthread_rwlock_unlock(&mx);
		printf("reader %li sleep %i seconds\n",pthread_self(),rand_var);
		sleep(rand_var);
	}
	printf("reader %i exit",pthread_self());
}
void writer(void *arg){
	srand(time(NULL)+pthread_self());
	for (int i = 0; i < 20; ++i){
		int rand_var=rand()%10;
		int rand_number_cell=rand()%*(int*)arg;
		pthread_rwlock_wrlock(&mx);
		printf("writer %li write in cell %i number %i\n",pthread_self(),rand_number_cell,rand_var);
		*(arr+rand_number_cell)=rand_var;
		pthread_rwlock_unlock(&mx);
		printf("writer %li sleep %i seconds\n",pthread_self(),rand_var);
		sleep(rand_var);
	}
	printf("writer %i exit",pthread_self());
}

int main(int argc, char const *argv[])
{
	const struct option long_opt[]={
		{"count",optional_argument,NULL,'c'},
		{NULL,0,NULL,0}
	};
	char ch=-1;
	while((ch=getopt_long(argc,argv,"c::",long_opt,NULL))!=-1)
	switch(ch){
		case 'c':
		count_el=atoi(optarg);
			break;
	}
	arr=malloc(sizeof(int)*count_el);
	pthread_attr_t attr;
	pthread_t thread_controller;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	pthread_t pthread[15];
	for (int i = 0; i < 5; ++i)
	{
		pthread_create(&pthread[i],NULL,&writer,&count_el);

	}
	for (int i = 5; i < 15; ++i)
	{
		pthread_create(&pthread[i],NULL,&reader,&count_el);
		pthread_create(&pthread[i],NULL,&reader,&count_el);
	}
	pthread_create(&thread_controller,&attr,&controller,NULL);
	for (int i = 0; i < 15; i++)
		pthread_join(pthread[i],NULL);
	free(arr);
	pthread_rwlock_destroy(&mx);
	pthread_exit(NULL);
}
