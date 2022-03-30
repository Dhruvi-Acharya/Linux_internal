#include<stdio.h>
#include<pthread.h>
#include<string.h>

struct thread_struct
{
	int id;
	char msg[15];
};

void *threadTask(void *obj)
{
	pthread_t thread_id;

	struct thread_struct *th1;
	
	th1 = (struct thread_struct *) obj; 
	
	thread_id = pthread_self();

	printf("\nThread Task Print thread id and structure mesaage of a given thread\n");
	
	printf("Thread ID : %lu\n",thread_id);
	
	printf("%d Thread Message : %s\n",th1->id,th1->msg);
}

int main()
{
	pthread_t thread1,thread2,thread_id;

	int rc;
	
	struct thread_struct t1,t2;
	
	t1.id=1;
	strcpy(t1.msg,"First thread\n");
	
	t2.id=2;
	strcpy(t2.msg,"Second thread\n");
	//t2.msg="Thread2";

//	thread_id = pthread_self();
	printf("Main\n");

	pthread_create(&thread1,NULL,threadTask,(void *)&t1);
	pthread_create(&thread2,NULL,threadTask,(void *)&t2);
//	pthread_create(&thread2,NULL,printHello,(void *)&t2);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("Exit from main function\n");
}