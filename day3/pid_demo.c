#include<stdio.h>
#include<unistd.h>

int main(void)
{
	printf("My process pid=%d",getpid());
	printf("parent id=%d",getppid());

	//while(1);

	return 0;
}