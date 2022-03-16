#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
	int fd,len;
 	char write_buf[6]="Linux";
	char read_buf[7];
 	creat("linuxkernel.txt",0777);
	fd = open("linuxkernel.txt",O_RDWR,0777);
	printf("%d",fd);
	len=write(fd,write_buf,6);
	close(fd);
	printf("return value from write option=%d\n",len);
	
	fd = open("linuxkernel.txt",O_RDWR,0777);
	//lseek(fd,0,SEEK_SET);
	lseek(fd,0,SEEK_CUR);
	read(fd,read_buf,len);
	printf("data from buffer(read optn) = %s\n",read_buf);
	//lseek(fd,4,SEEK_SET);
	//lseek(fd,0,SEEK_END);

	

	

close(fd);
return 0;
}
