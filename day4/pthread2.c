#include<pthread.h>

pthread_t tid,tid1;

void* thread1(void *arg)
{
	printf("\nnewly created thread1 executing\n");
	for(int i =0; i<5;i++)
		printf("%d ",i);
}

void* thread2(void *arg)
{
	printf("\nnewly created thread2 executing\n");
	for(int i =10; i<50;i=i+10)
		printf("%d ",i);
}

int main(void)
{
	int ret = pthread_create(&tid,NULL,thread1,NULL);

	int ret1 = pthread_create(&tid1,NULL,thread2,NULL);

	if(ret)
	{
		printf("thread1 is not created\n");
	}
	else
	{
		printf("thread1 is created\n");
	}

	if(ret1)
	{
		printf("thread2 is not created\n");
	}
	else
	{
		printf("thread2 is created\n");
	}

//	sleep(2);
	pthread_join(tid,NULL); //make parent to wait to execute 

	pthread_join(tid1,NULL);
	return 0;
}