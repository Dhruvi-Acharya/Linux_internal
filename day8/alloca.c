#include<stdio.h>
#include<string.h>

int main(){
	char *str1 = "linux";
	char *str2 = "kernel";

	char *name = (char *)alloca(strlen(str1) + strlen(str2) + 1);
	stpcpy(stpcpy(name,str1),str2);

	printf("the copied string is : %s\n",name);

	return 0;
}