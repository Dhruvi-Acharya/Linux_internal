#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void* start_one(void *arg)
{
	printf("\nnewly created thread1 executing\n");
	for(int i =0; i<10;i++)
		printf("thread1\n");
}

void* start_two(void *arg)
{
	printf("\nnewly created thread2 executing\n");
	for(int i =0; i<10;i++)
		printf("thread2\n");
}

int main(void)
{
	pthread_t tid,tid1;
//	getchar();
	
	pthread_create(&tid,NULL,start_one,NULL); 

	pthread_create(&tid1,NULL,start_two,NULL);

	//getchar();
printf("hi");
	//sleep(2);
	//pthread_join(tid1,NULL); //make parent to wait to execute 

	//pthread_join(tid,NULL);

	printf("Execution end of main thraed\n");
	return 0;
}
