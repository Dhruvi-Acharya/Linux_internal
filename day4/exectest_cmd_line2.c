#include<stdio.h>

int main()
{
	printf("I am going to execute the ls program");
	execl("/home/dhruvi/Linux_internal/day4/exectest_cmd_line","./exectest_cmd_line","aa","bb","cc",NULL); //is OS defined pg, final arg 0 indicates end of string

	return 0;
}