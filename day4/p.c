//child and parent process child executing exec program parent waiting to execute child process
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int pid;
	pid=fork();

	if(pid==0)//child pid<0 error fprintf(stderr ,fork failed) exit(-1)
	{
		printf("child process %d\n",getpid());
	  execl("/home/dhruvi/Linux_internal/day4/exectest_cmd_line","./exectest_cmd_line","aa","bb","cc",NULL);

	  //bin/ls ls null
	}
	else
	{
		printf("parent process %d\n",getpid());
		wait(NULL);
		printf("child complete\n");
		exit(0);
	}
}
