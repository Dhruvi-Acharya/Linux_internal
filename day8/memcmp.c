#include<stdio.h>
#include<string.h>

int main(){
	char buf1[10],buf2[10];
	int ret;

	memcpy(buf1,"xmadam",5); // madam---97--108
	memcpy(buf2,"zmad",5); //mad----65---76

	ret = memcmp(buf1,buf2,5); // if buf1 is grater than return 1 same 0 buf2 grater -1

	printf("%d\n",ret);

	if(ret>0){
		printf("buf1 is grater than buf2\n");
	}else if(ret<0){
		printf("buf1 is less than buf2\n");
	}else{
		printf("both are same\n");
	}
	return 0;
}