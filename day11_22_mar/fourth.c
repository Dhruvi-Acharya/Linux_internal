#include<stdio.h>
#include<string.h>

struct A
{
	int roll;
	char name[40],gender;
	float height;
	char g;
};

int main(){
	struct A first;
	printf("size of struct A is: %3d\n",sizeof(first));
	printf("size of struct A is: %3d\n",sizeof(int));
	printf("size of struct A is: %3d\n",sizeof(char));
	printf("size of struct A is: %3d\n",sizeof(float));
}