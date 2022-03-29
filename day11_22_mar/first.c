#include<stdio.h>
#include <string.h>

struct student
{
	int roll;
	char name[40],gender;
	float height;
}first;

int main(){
	struct student second;
	struct student third={103,"Dhruvi",'f',5.11};

	printf("\nRoll no. Name\t\t\t Gender\t Height\n");
	first.roll=101;
	strcpy(first.name,"Nimi");
	first.gender='f';
	first.height=5.3;

	printf("\n %3d\t%-30s%c\t%1.2f\n",first.roll,first.name,first.gender,first.height);
	printf("\n %3d\t%-30s%c\t%1.2f\n",third.roll,third.name,third.gender,third.height);
}