#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main(int argc, char const *argv[])
{
	
	int ret1,ret2,i,cnt =0;
	errno=0;

	ret1 = nice(1);
	//ret2 = nice(20);

	if(ret1 == -1 && errno !=0)
		perror("\nnice\n");
	else
		printf("nice value is now %d\n",ret1);

	while(1)
	{
		printf("Process with nice value %d count = %d\n",ret1,cnt);

		for(i=0;i<100;i++);
			cnt++;
	}
	return 0;
}