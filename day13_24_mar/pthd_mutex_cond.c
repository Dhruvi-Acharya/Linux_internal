#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int done = 1;

//thread function
void* foo(void *arg){
	char *str = (char*)arg;

	printf("thread task called by: %s\n",str);

	//acquire lock
	pthread_mutex_lock(&lock);

	if(done == 1){

		// let's wait on condition
		printf("waiting on condition variable cond1\n");
		pthread_cond_wait(&cond1,&lock);
	}
	else{
		//let's signal condition variable cond1
		printf("Signling condition variable cond1\n");
		pthread_cond_signal(&cond1);
	}

	//release lock
	pthread_mutex_unlock(&lock);

	printf("Returning thread\n");

	return NULL;
}

//driver code
int main(){

	pthread_t tid1,tid2;

	// create threa 1
	pthread_create(&tid1,NULL,foo,"TH Done");

	//sleep for 1 sec so that thread 1 would get a chance to run first
	sleep(1);

	//let's wait on condition variable cond1
	done=2;

	//create thread 2
	pthread_create(&tid2,NULL,foo,"THD two");

	// wait for the completion of thread 2 
	pthread_join(tid2,NULL);

	return 0;
}