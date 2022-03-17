#include<stdio.h>
#include<unistd.h>

void main()
{
	int pid;

	printf("current process id: %d\n",getpid());

	pid = fork(); //child sent parent 0 return child pro
	
	if(pid==0)
	{
		printf("Parent\n");
		printf("new child process id: %d\n",getpid());
		printf("new child parent process id: %d\n",getppid());
	}
	else
	{
		sleep(3);
		printf("child\n");
		printf("parent process id: %d\n",getpid());
		printf("parents parent process id: %d\n",getppid());
	}
	while(1);
}