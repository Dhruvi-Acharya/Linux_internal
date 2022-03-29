#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int i;
	printf("file name: %s\n",argv[0]);
	printf("total number of argument passed: %d\n",argc);
	printf("argument passed\n");

	for(i=0;i<argc;i++)
		printf("%s\n",argv[i]);

	printf("\n");
	return 0;
}