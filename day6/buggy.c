#include<stdio.h>
#include<stdlib.h>

void buggyy()
{
	int *intptr;
	int i;
	intptr = (int *)malloc(sizeof(int)*5); //allocating 20 bytes

	printf("MALLOC checking: Add=%08x and size=%d\n",intptr,sizeof(int )*5);

	for(int i=0;i<=4;i++) //change the loop interation standard c library problem that malloc can allocate more bytes than the required or allocate
	{
		*intptr=100;
		printf("value at ptr intptr = %d\n",(*intptr));
		intptr++;
	}
}

int main()
{
	buggyy();
	return 0;
}