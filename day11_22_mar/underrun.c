//program to check the lower boundary memory violation

#include<stdio.h>
#include<stdlib.h>
//extern int EF_PROTECT_BELOW=1;
//export EF_PROTECT_BELOW=1; write this in the command line prompt before executing the gcc compile

void buggyy()
{
	int *intptr;
	int i;
	intptr = (int *)malloc(sizeof(int)*5);

	printf("MALLOC checking: Add=%08x and size=%d\n",intptr,sizeof(int )*5); //int data type = 4 bytes

	for(int i=0;i<3;i++) //change the loop interation standard c library problem that malloc can allocate more bytes than the required or allocate
	{
		*intptr=100;
		printf("value at ptr intptr = %d\n",(*intptr));
		intptr--;
	}
}

int main()
{
	buggyy();
	return 0;
}