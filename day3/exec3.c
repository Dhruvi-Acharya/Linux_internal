#include<stdio.h>

int main()
{

	int ret;

	ret = execl("/usr/bin/vim","vim","info1.txt",0); //create and open the file named info1.txt

	if(ret==-1)
		printf("Error %d\n",ret);

	printf("End\n"); //not executed

	return 0;
}