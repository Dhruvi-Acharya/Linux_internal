#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int pid,status;

	printf("parent: %d\n",getpid());

	pid=fork();

	if(pid==0)
	{
		printf("child %d\n",getpid());
		sleep(2);
		exit(0);
	}

	printf("parent reporting exit of child whose pid=%d\n",waitpid(pid,&status,0));
	return 0;
}