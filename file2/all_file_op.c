#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd,len;
	char read_buf[20],write_buf[20]="hello, how are you?";

	fd=open("demo1.txt",O_CREAT |O_RDWR,777);
	printf("fd = %d\n",fd);
	len = write(fd,write_buf,20);
	printf("len=%d",len);

	//lseek(fd,0,SEEK_SET);
	lseek(fd,-1,SEEK_END);
	read(fd,read_buf,len);
	printf("readdata: %s",read_buf);

	close(fd);

}