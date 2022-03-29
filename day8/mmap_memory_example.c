#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
	char *c;

	c = mmap(0,50,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0); //msg sucess
	perror("mmap");

	strcpy(c,"linuxkernel"); // kernel region in user space
	printf("%s\n",c);

	//deallocate all resources
	munmap(c,50); //malloc after free

	//printf("%s\n",c);

	return 0;
}