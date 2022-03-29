#include<pthread.h>
#include<stdio.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *myinit()
{
	printf("\n I am in init function\n");
}

void *mythread(void *i)
{
	printf("\n i am in my thraed %d\n",(int *)i);
	pthread_once(&once,(void *)myinit);
	sleep(10);
	printf("\n exit from mythread %d\n",(int *)i);
}

int main()
{
	pthread_t thread,thread1,thread2;
	pthread_create(&thread,NULL,mythread,(void *)1);
	sleep(2);
	pthread_create(&thread1,NULL,mythread,(void *)2);
	sleep(2);
	pthread_create(&thread2,NULL,mythread,(void *)3);
	printf("\n exit from main function\n");
	pthread_exit(NULL);
}