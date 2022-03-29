#include<stdio.h>
#include<string.h>

int main()
{
	const char str[] = "linuxkernel.com";
	const char ch = '.';
	char *ret;

	printf("String before set initialization is %s\n",str);

	//memset(str,ch,strlen(str));

	ret = memchr(str,ch,strlen(str));

	printf("string after **%c** is %s\n",ch,ret+3);

	printf("string after **%c** is %s\n",ch,ret-7);

	return 0;
}