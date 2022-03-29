#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int i = 10; //shared variable protected variable

pthread_mutex_t mutex;

void *thread1Increment(void *arg)
{
	printf("Applying Lock\n");

	pthread_mutex_lock(&mutex); //applying mutex lock
	
	i=i+10;

	printf("After increament: %d\n", i);
	
	pthread_mutex_unlock(&mutex); // unlocking

	printf("Unlock\n");
}

void *thread2Decrement(void *arg)
{
	printf("Applying Lock\n");

	pthread_mutex_lock(&mutex); // applying lock
	
	i=i-5;

	printf("After decrement: %d\n", i);

	pthread_mutex_unlock(&mutex); //unlocking

	printf("Unlock\n");
}

int main()
{
	pthread_t thread1,thread2; 

	pthread_mutex_init(&mutex,NULL);

	pthread_create(&thread1,NULL,thread1Increment,NULL);
	pthread_create(&thread2,NULL,thread2Decrement,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("Variable value: %d\n", i);

	return 0;
}