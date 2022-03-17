#include<stdio.h>
#include<unistd.h>

void main()
{
	int pid;

	printf("current process id: %d\n",getpid());

	pid = fork(); 
	
	if(pid)
	{
		printf("Parent\n");
		printf("new child process id: %d\n",getpid());
		fork();
		printf("new child child process id: %d\n",getpid());
		printf("new child parent process id: %d\n",getppid());
	}
	else
	{
		//sleep(3);
		printf("child\n");
		printf("child parent process id: %d\n",getpid());
		fork();
		printf("child child process id: %d\n",getpid());
		//printf("parents parent process id: %d\n",getppid());
	}
	while(1);
}
