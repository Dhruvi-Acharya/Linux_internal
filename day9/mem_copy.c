#include<stdio.h>
#include<string.h>

void copyfun(char *src,char *dest, int count)
{
	int i;

	for(i=0;i<count;i++)
	{
		*dest=*src;
		dest++;
		src++;
	}
}
int main(){
	
	char buf1[10]="Hello";
	char buf2[10];

	copyfun(buf1,buf2,10);

	printf("buffer1: %s\n",buf1);
	printf("buffer2: %s\n",buf2);

	return 0;
}