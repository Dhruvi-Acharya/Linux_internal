#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
	int fd;

	mkfifo("newfifo",0666);

	char arr1[100],arr2[100];

	while(1){
		//open fifo for write only
		fd = open("newfifo",O_WRONLY);

		/// take an input arr2 from user 
		fgets(arr2,100,stdin);

		// write the input arr2 on fifo and close it
		write(fd,arr2,strlen(arr2)+1);

		close(fd);

		//open fifo for read only

		fd = open("newfifo",O_RDONLY);

		//read from fifo
		read(fd,arr1,sizeof(arr1));

		// print the read message
		printf("User2: %s\n",arr1);
		close(fd);
	}

	return 0;
}