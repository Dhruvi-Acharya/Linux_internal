#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd,len;
	char read_buf[20],write_buf[20]="hello, how are you?";

	fd=open("demo.txt",O_CREAT |O_RDWR,777); // opening file if already created otherwise create file
	printf("fd = %d\n",fd);
	
	len = write(fd,write_buf,20); // writing data to file
	printf("len = %d\n",len);

	lseek(fd,7,SEEK_SET); // setting lseek position
	read(fd,read_buf,len); //reading data
	printf("read data: %s\n",read_buf);

	close(fd); // closing fd

}