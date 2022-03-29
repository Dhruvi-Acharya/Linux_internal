#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

pthread_t tid;

void* thread_task(void *arg) //thread task function
{
	printf("newly created thread executing\n");

	for(int i=1;i<=5;i++)
		printf("%d ",i);

	while(1);
}

int main(void)
{
	int ret = pthread_create(&tid,NULL,thread_task,NULL); //creating thread 
	int t=0;

	printf("Thread id: %lu\n",tid); //printing thread id
	
	sleep(2); // make parent sleep

	t=pthread_cancel(tid); //cancelling thread

	printf("\nThread cancel value: %d\n",t); // on successful thread cancel it will return 0 


	if(t==0) // checking thread cancel or not 
		printf("Thread cancelled successfully\n");

	return 0;
}