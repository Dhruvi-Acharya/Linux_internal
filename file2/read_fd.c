#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd,res;
	int x;
	char write_buf[60];

	fd=open("linuxabc.txt",O_CREAT | O_RDWR, 0777); //ope file if not exist then the file is created
	printf("fd=%d\n",fd);

	if(fd<0)
		printf("problem");

	read(fd,write_buf,60);
	printf("%s",write_buf);

	close(fd);
	return 0;
}
