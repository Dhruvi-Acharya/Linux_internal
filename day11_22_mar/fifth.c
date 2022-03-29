#include<stdio.h>
#include<string.h>

struct A
{
	int roll;
	char name[40],gender __attribute__((aligned(2)));
	float height;
}__attribute__((packed));

int main(){
	struct A first;
	printf("size of struct A is: %3d\n",sizeof(first));
	printf("size of struct A is: %3d\n",sizeof(int));
	printf("size of struct A is: %3d\n",sizeof(char));
	printf("size of struct A is: %3d\n",sizeof(float));
}