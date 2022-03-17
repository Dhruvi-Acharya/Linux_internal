#include<stdio.h>

int main()
{
	printf("I am going to execute the ls program\n");
	execl("/home/dhruvi/Linux_internal/day3/pid_demo.c","./vfork",0); //is OS defined pg, final arg 0 indicates end of string

	printf("I executed the ls program\n");
	printf("I executed the ls program\n");
	printf("I executed the ls program\n");

	return 0;
}