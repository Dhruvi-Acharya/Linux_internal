#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("I am going to excute the execl program\n");
	execl("/usr/bin/pstree","pstree",NULL);	
}
