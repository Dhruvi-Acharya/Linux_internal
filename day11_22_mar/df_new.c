// program that shows freeing a ptr which is already free giving error 
// check these using gdb lefence valgrind
// gdb shows SIGABRT aborted
// electric fence address not from malloc illegal instruction core dumped
// valgrind invalid free

#include<stdio.h>
#include<stdlib.h>

void buggy(int *p){ // fun using that value
	p[0]=10; //writing address
	free(p);//free ptr
}

int main(){
	int *ptr;
	ptr = (int *)malloc(4); //creating 4 bytes
	buggy(ptr); // passing address of 4 bytes to through a ptr
	free(ptr);//double free trying to free a ptr already freed error
}