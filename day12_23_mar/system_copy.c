#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char buff_comm[5];
	int i,j;
	strcpy(buff_comm,"ls -l");

	printf("system() library function uses fork() to create a child process\n");
	printf("child process executes execl() which loads and run new program provided by a system() arguments\n");

	j=system(buff_comm); // create child and execute the command and parent wait child to execute the command and in this j return 0 beacuse shell is busy in running command

	//i=system(NULL); // it will return 0 becuase not executing any command and shell is availble

	//printf("when passing null return %d\n",i);
	printf("when passing command return %d\n",j);

	//system(); //return too few arguments error
	return 0;
}