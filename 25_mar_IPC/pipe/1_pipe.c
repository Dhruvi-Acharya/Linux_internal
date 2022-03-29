#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int p[2];

	pipe(p); // fd 0 p[0]read end and fd 1 p[1] write end
	printf("Read end of pipe = %d\t write end of pipe = %d\n", p[0],p[1]);

	if(fork()){ //parent 
		char s[20];
		printf("In parent enter data...\n");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
	}
	else{ //child 
		char buf[20];
		printf("In child...\n");
		read(p[0],buf,sizeof(buf));
		printf("child pro printin... data of the parent process..%s\n",buf);
	}

	return 0;
}