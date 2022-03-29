#include<stdio.h>
#include<unistd.h>

int main(){
	long int page_size = sysconf(_SC_PAGESIZE);

	printf("My page size: %ld\n",page_size);

	void* c1 = sbrk(0); //end location of program segment current pointer 

	printf("program break address: %p\n",c1);
	printf("sizeof char : %lu\n",sizeof(char));

	c1=(void *)((char*) c1 + 9); //move pointer 9 bytes

	printf("c1: %p\n",c1);

	brk(c1); //set at c1 location 
	void* c2 = sbrk(0); // getting current location

	printf("program break address: %p\n",c2);
}