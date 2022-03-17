#include<stdlib.h>
#include<stdio.h>

void callback1(void)
{
	printf("callback1 function call\n");
}

void callback2(void)
{
	printf("callback2 function call\n");
}

void callback3(void)
{
	printf("callback3 function call\n");
}

int main()
{
	printf("registering callback1\n");
	atexit(callback1);
	printf("registering callback2\n");
	atexit(callback2);
	printf("registering callback3\n");
	atexit(callback3);
	printf("main()..exiting now\n");

	exit(0);
	//_exit(0); //not calling the register function

	return 0;
}