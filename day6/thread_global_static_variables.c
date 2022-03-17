#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sharedVar = 5; //shared variable protected variable

void *thread_inc(void *arg)
{
	sharedVar++;

	printf("after increament %d\n", sharedVar);
}

void *thread_dec(void *arg)
{
	sharedVar--;

	printf("after decrement %d\n", sharedVar);
}

int main()
{
	pthread_t t1,t2;

	pthread_create(&t1,NULL,thread_inc,NULL);
	pthread_create(&t2,NULL,thread_dec,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("shared variable %d\n", sharedVar);

	return 0;
}