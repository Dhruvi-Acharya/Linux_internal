#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

int sharedVar = 5; //shared variable protected variable

sem_t my_sem; //declare semaphore variable

void *thread_inc(void *arg)
{
	sem_wait(&my_sem); //applying lock
	sharedVar++;

	printf("after increament %d\n", sharedVar);
	sem_post(&my_sem); //unlock
}

void *thread_dec(void *arg)
{
	sem_wait(&my_sem); //apply lock
	sharedVar--;

	printf("after decrement %d\n", sharedVar);
	sem_post(&my_sem); //unlock
}

int main()
{
	pthread_t t1,t2;

	sem_init(&my_sem,0,1); //initializing semaphore object

	pthread_create(&t1,NULL,thread_inc,NULL);
	pthread_create(&t2,NULL,thread_dec,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("shared variable %d\n", sharedVar);

	return 0;
}