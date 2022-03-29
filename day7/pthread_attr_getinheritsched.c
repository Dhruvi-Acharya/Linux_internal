#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *proc(void* param)
{
	sleep(3);
	return 0;
}

int main(int argc, char *argv[])
{
	pthread_attr_t attr;
	pthread_t id;
	int err,info;

	pthread_attr_init(&attr);
	pthread_attr_getinheritsched(&attr,&info);

	switch(info)
	{
		case PTHREAD_INHERIT_SCHED:
		printf("\n sched \n");
		break;
		case PTHREAD_EXPLICIT_SCHED:
		printf("\n explicit\n");
		break;
	}

	pthread_create(&id,&attr,proc,NULL);

	return 0;
}