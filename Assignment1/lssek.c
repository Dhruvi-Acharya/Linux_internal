#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	int fd;
	int len;
	char read_buf[11];
	fd=open("file1.txt",O_CREAT|O_RDWR,0777);

	lseek(fd,0,SEEK_END);
	read(fd,read_buf,11);
	printf("the data from the write buffer is %s\n",read_buf);	
	//lseek(fd,4,SEEK_CUR);
	lseek(fd,0,SEEK_SET);
	read(fd,read_buf,6);
	printf("the data from the write buffer is %s\n",read_buf);
	//lseek(fd,-3,SEEK_SET);
	//lseek(fd,2,SEEK_SET);
	



close(fd);

return 0;

}

