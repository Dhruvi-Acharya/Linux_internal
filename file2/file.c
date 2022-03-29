#include<stdio.h>
#include<fcntl.h>

void main()
{
	int fd=creat("demo.txt",777);
	printf("fd = %d\n",fd);
}
