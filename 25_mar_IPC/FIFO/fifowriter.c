#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	char s[20];
	int fd;

	mkfifo("newfifo11",0644); // newfifo1 is an pipe  a file named pipe create fifo(named pipe)

	perror("mkfifo");

	printf("Before open()...\n");
	fd = open("newfifo11",O_WRONLY); // open fifo for write only
	printf("After open()...\n");

	printf("Enter data...\n");
	scanf("%s",s);

	write(fd,s,strlen(s)+1); // std wt(); internally file write data to 
	return 0;
}

// fifo is pipe with name named pipe will have name in file system