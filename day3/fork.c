#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	
	printf("hello\n");
	fork();//2
	fork();//4
	fork();//8
	printf("number\n");
	return 0;
}