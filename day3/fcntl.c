#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2,fd3,fd4;

	fd1=open("demo.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);

	//fd2=open("demo1.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);

	printf("fd1=%d",fd1);
	//printf("fd2=%d",fd2);

	fd3=fcntl(fd1,F_DUPFD,55);//dup()

	printf("fd3=%d",fd3);
	printf("fd1=%d",fd1);

	close(fd3);
	//close(fd2);
	close(fd1);
}