#include<pthread.h>
#include<stdio.h>

pthread_t tid;

static void* thread1(void *arg)
{
	char *s = (char *)arg;
	printf("%s\n",s);
//	printf("newly created thread executing\n");
//	return NULL;
}

int main(int argc,char *argv[])
{
	int ret = pthread_create(&tid,NULL,thread1,"Hello World");

	/*if(ret)
	{
		printf("thread is not created\n");
	}
	else
	{
		printf("thread is created\n");
	}*/
	printf("Messages from main()\n");
	sleep(3);
	//pthread_join(tid,NULL); //make parent to wait to execute 
	exit(0);
}