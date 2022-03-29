#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>




int main()
{
	int pid_1;
	printf("curr process pid=%d\n",getpid());
	pid_1=fork();
	if(pid_1==0)
	{
		printf("new child pid =%d\n",getpid());
		printf("new child parent pid =%d\n",getppid());
		execl("/bin/ls","ls",NULL);
	}
	else
	{
		//sleep(3);
		wait(NULL);
		printf("\nchild complete\n");
		//exit(0);
	}
}