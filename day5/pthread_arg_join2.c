#include<pthread.h>
#include<stdio.h>

pthread_t tid;

static void* thread1(void *arg)
{
	char *s = (char *)arg;
	printf("%s\n",s);
	sleep(5);
	return (void*)strlen(s);
	return 0;
//	printf("newly created thread executing\n");
//	return NULL;
}

int main(int argc,char *argv[])
{
	pthread_t t1;
	void *res;
	int s;

	pthread_create(&t1,NULL,thread1,"Hello World");

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
	pthread_join(t1,&res); //make parent to wait to execute 

	printf("thread returned %ld\n",(long)res);
	exit(0);
	exit(0);
}