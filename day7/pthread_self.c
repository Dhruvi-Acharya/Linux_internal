#include<stdio.h>
#include<pthread.h>

struct my_thread
{
	int thread_id;
	char msg[100];
};

void *printHello(void *threadobj)
{
	pthread_t thread_id;
	struct my_thread *t1;
	t1=(struct my_thread *) threadobj; //this typecast is required because we are passing pointer argument
	thread_id = pthread_self();
	printf("\n thread ID : %u",thread_id);
	printf("\n %d Thread Message : %s\n",t1->thread_id,t1->msg);
}

int main()
{
	pthread_t thread2,thread3,thread4,thread_id;
	int rc;
	struct my_thread t2,t3,t4;
	t4.thread_id=4;
	strcpy(t4.msg,"I am fourth thread\n");
	t2.thread_id=2;
	strcpy(t2.msg,"I am second thread\n");
	t3.thread_id=3;
	strcpy(t3.msg,"I am third thread\n");

	thread_id = pthread_self();
	printf("\n main thread\n");

	pthread_create(&thread4,NULL,printHello,(void *)&t4);
	pthread_create(&thread3,NULL,printHello,(void *)&t3);
	pthread_create(&thread2,NULL,printHello,(void *)&t2);

	printf("\n Exit from main function\n");
	pthread_exit(NULL);
}