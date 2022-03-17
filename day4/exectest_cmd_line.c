#include<stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	printf("\n file name: %s\n",argv[0]); //a.out
	printf("total no. of argumanets: %d\n",argc);
	printf("Arguments passed: ");
	for(i=0;i<argc;i++)
		printf("%s ",argv[i]);
	printf("\n");
	return 0;
}