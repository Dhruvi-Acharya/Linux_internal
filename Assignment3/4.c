#include<stdio.h>
#include<pthread.h>

void *mythreadTask(void *i)
{
	printf("I am in %d Thread \n",(int *)i);
}

int main()
{
	pthread_t tid;
	struct sched_param param;
	int priority,policy,ret;

	ret = pthread_getschedparam(pthread_self(),&policy,&param); // get default priority and policy

	if(ret !=0)
		perror("getschedparam\n");

	printf("\n------------------Main Thread--------------\nPolicy : %d \t Priority : %d\n",policy,param.sched_priority);

	policy=SCHED_RR; // setting RR policy 
 
	param.sched_priority = 10; // giving priority

	ret = pthread_setschedparam(pthread_self(),policy,&param); // setting our priority and policy

	if(ret!=0)
		perror("getschedparam\n");

	ret = pthread_getschedparam(pthread_self(),&policy,&param);

	if(ret!=0)
		perror("getschedparam\n");

	printf("\n--------------------Main Thread-----------------\n Policy : %d \t Priority : %d\n",policy,param.sched_priority);

	return 0;
}