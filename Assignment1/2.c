#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
int main()
{
	int fd;
	char buffer[50];

	fd = open("file1.txt",O_RDONLY); //open file to read data Hello Good Morning

	lseek(fd,4,SEEK_SET); // setting 4th position from starting so pointer at 4th position : o Good Morning
	lseek(fd,1,SEEK_CUR); // increase pointer 1 from current position : Good Morning
	lseek(fd,-5,SEEK_END); // setting backword from ending position : ning

	read(fd,buffer,50); // reading data
	printf("data read from buffer is : %s\n",buffer); // we will get ning 

	close(fd);
	return 0;
}

/*#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd1,fd2,total;
	char buffer[50];
	char buffer1[50];

	fd1 = open("file1.txt",O_RDONLY);
	//fd2 = open("file2.txt",O_CREAT | O_RDWR);

		read(fd1,buffer,50);

		total=lseek(fd1,0,SEEK_END);

		printf("total bytes in file is: %d\n",total);

		write(fd2,buffer1,total);

		printf("Data in file is: %s\n",buffer1);

		close(fd1);
	//	close(fd2);

		fd2 = open("file2.txt",O_RDONLY);

printf("reading data from starting to 4th position:\n");

		lseek(fd1,4,SEEK_SET);
		fflush(buffer1);
		read(fd1,buffer1,total);
		printf("data from buffer= %s\n",buffer1);
/*
		buffer1[0]='\0';
//close(fd2);
		lseek(fd2,5,SEEK_CUR);
read(fd2,buffer1,total);
		printf("data from buffer= %s\n",buffer1);


		lseek(fd2,-4,SEEK_END);

		//read(fd2,buffer1,total);

		printf("data from buffer= %s\n",buffer1);

		close(fd1);
		close(fd2);	
	

	return 0;
}*/