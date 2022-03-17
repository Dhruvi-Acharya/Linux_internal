#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3,fd4;
	fd1=open("demo.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);
	fd2=open("demo1.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);

	printf("fd1=%d\n",fd1);
	printf("fd2=%d\n",fd2);

	fd3=dup(fd1,44);

	printf("fd3=%d\n",fd3);

	close(fd3);
	close(fd2);
	close(fd1);
}