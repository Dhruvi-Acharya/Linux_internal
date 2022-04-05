// synchronization between process and thread

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<bits/types.h>
#include<sys/types.h>
#include<semaphore.h>

static pthread_spinlock_t spinlock; //declare
volatile int slock;

void *spinlockThread(void *i)
{
	int rc;
	int count=0;

	printf("Entered thread %d, getting spin lock \n",(int *)1);

	rc=pthread_spin_lock(&slock); // after parent unlock thread apply lock

	printf("%d Thread unlock the spin lock\n",(int *)1);

	rc=pthread_spin_unlock(&slock); //unlock

	printf("%d Thread complete\n",(int *)1);

	return NULL;

}

int main()
{
	int rc=0;
	pthread_t t1,t2;

	if(pthread_spin_init(&slock,PTHREAD_PROCESS_PRIVATE)!=0) // initialization
		perror("init\n");

	printf("Main get spin lock\n");
	rc=pthread_spin_lock(&slock); //main apply lock

	printf("main create the spin lock thread\n");

	rc=pthread_create(&t1,NULL,spinlockThread,(int *)1);


	printf("main wait a bit holding the spin lock\n");
	
	sleep(5);

	printf("Main now unlock the spin lock\n");

	
	rc=pthread_spin_unlock(&slock); // main release lock

	if(rc==0)
		printf("main thread successfully unlocked\n");
	else
		printf("main thread unsuccessfully to unlocked\n");

	printf("main wait for the thread to end\n");

	rc=pthread_join(t1,NULL);
	rc=pthread_spin_destroy(&slock);

	printf("main comleted\n");

	return 0;
}
