// C++ program to demonstrate creating processes using fork()
#include <unistd.h>
#include <stdio.h>

int main()
{
	int c1,c2;

	c1 = fork(); // Creating first child
	
	if (c1==0) //child1 
	{
		printf("First child\n");
		printf("child1 process id is: %d \n", getpid());
		printf("parent process id is: %d \n", getppid());
		for(int i=1;i<=5;i++) //child1 task print 1 to 5
		{
			printf("%d\n",i);
		}
		
	}
	else
	{
		sleep(3);
		c2 = fork(); //second child
		if(c2==0){
			printf("Second child\n");
			printf("child2 process id is: %d \n", getpid());
			printf("parent process id is: %d \n", getppid());
		
			for(int i=10;i<=50;i=i+10) //child2 task print 10 to 50
			{
				printf("%d\n",i);
			}
		}
		else{ //parent process
			sleep(3);
			printf("Parent process\n");
			printf("parent id: %d\n",getpid());

		}	
	}
	return 0;
}
