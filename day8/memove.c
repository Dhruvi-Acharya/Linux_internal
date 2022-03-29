#include<stdio.h>
#include<string.h>

int main(){
	char dest[]="oldstring hello";
	const char src[]="newstring hello hi";

	printf("before mmove dest = %s and src = %s\n",dest,src);

	memmove(dest,src,30);

	printf("after mmove dest = %s and src = %s\n",dest,src);

	return 0;
}