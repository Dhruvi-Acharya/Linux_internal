#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *myinit()
{
	printf("I am in init function calling only once\n");
}

void *mythread(void *i)
{
	printf("I am in thread %d\n",(int *)i);
	pthread_once(&once,(void *)myinit);
	//sleep(10);
	printf("Exit from thread %d\n",(int *)i);
}

int main()
{
	pthread_t thread1,thread2;

	pthread_create(&thread1,NULL,mythread,(void *)1);
	sleep(2);

	pthread_create(&thread2,NULL,mythread,(void *)2);
	sleep(2);

	printf("Exit from main function\n");
	pthread_exit(NULL);
}