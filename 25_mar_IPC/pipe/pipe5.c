#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int fds[2];

void parent_code(){
	char *buf1="aaaaaaaaaaaaaaaaaaaaa";
	char *buf="bbbbbbbbbbbbbbbbbbbb";
	close(fds[0]);
	write(fds[1],buf,20);
	write(fds[1],buf1,20);
	printf("end of parent\n");
}

void child_code(){
	char buf[100];
	int n,i;
	close(fds[1]);
	n = read(fds[0],buf,100);
	printf("no of chars read = %d\n",n);

	for(i=0;i<n;i++)
		printf("%c",buf[i]);
	printf("End of child\n");
}

void main(){

	int i,fd[2],nbytes;
	char string[]="Linux kernel technology\n";
	char readbuffer[50];
	pid_t p;

	pipe(fd);

	
	if((p==fork())== -1){
		perror("fork\n");
		exit(1);
	}

	if(p==0){
		close(fd[0]);
		write(fd[1],string,(strlen(string)+1));
		exit(0);

		//child_code();
	}
	else{
		close(fd[1]);

		nbytes= read(fd[0],readbuffer,sizeof(readbuffer));

		for(i=0;readbuffer[i];i++){
		if(readbuffer[i] >= 'a' && readbuffer[i] <= 'z')
			readbuffer[i] = readbuffer[i] -32;
		}

		printf("received string %s\n",readbuffer);
		//parent_code();
	}
}