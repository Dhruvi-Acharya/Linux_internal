#include<pthread.h>
#include<stdio.h>

void *threadTask(void *arg)
{
	pthread_detach(pthread_self());

	printf("Thread sleeping 2 sec\n");
	sleep(2);
	printf("slept 2 sec\n");
	return NULL;
}

int main()
{
	pthread_t t1;

	pthread_create(&t1,NULL,threadTask,NULL);

	printf("main\n");

	//pthread_exit(NULL);
	pthread_join(&t1,NULL);

	printf("Main End\n");

	return 0;
}