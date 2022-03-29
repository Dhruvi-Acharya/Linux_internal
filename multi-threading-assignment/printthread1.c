#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

pthread_t tid;

void* thread1(void *arg)
{
	pid_t pid;
	pthread_t tid;

	tid=pthread_self(); //thread id 
	pid=getpid(); //process id

	printf("Thread task is to print thread id and process id\n");
	
	printf("Thread id: %lu\n",tid);
	printf("Process id: %u\n",pid);

	return 0;
}

int main(void)
{
	int ret = pthread_create(&tid,NULL,thread1,NULL);

	if(ret) //checking weather thread is created or not
	{
		printf("Thread is not created\n");
	}
	else
	{
		printf("Thread is created successfully\n");
	}

	sleep(2);

	return 0;
}