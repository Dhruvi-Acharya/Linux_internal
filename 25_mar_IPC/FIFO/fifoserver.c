#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(void){
	printf("Server listening\n");

	//create fifo
	int code = mkfifo("cli_ser_fifo",0764);

	if(code == -1){
		perror("mkfifo returned an error file may already exist\n");
	}

	//open read end
	int fd = open("cli_ser_fifo",O_RDONLY);

	if(fd == -1){
		perror("cannot open FIFO for read\n");
	}

	printf("FIFO OPEN\n");

	//read string upto 100 characters

	char serverrcv[100]; // string buffer

	memset(serverrcv,0,100); //set ser buff with zeros

	int res;
	char len;

	while(1){
		res = read(fd,&len,1);
		if(res == 0){
			break;
		}
		read(fd,serverrcv,len);

		//serverrcv[(int)len] = 0

		printf("server received: %s\n",serverrcv);
	}

	printf("EOF reached\n");

	close(fd);
	printf("FIFO closed\n");

	return 0;
}