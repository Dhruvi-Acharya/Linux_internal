//child and parent process child executing exec program parent waiting to execute child process
#include<stdio.h>
#include<unistd.h>

int main()
{
	
	printf("I am going to execute new command line program\n");
	execl("/home/dhruvi/Linux_internal/day4/exectest_cmd_line","./exectest_cmd_line","aa","bb","cc",NULL);
	return 0;
}
