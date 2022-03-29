#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/mman.h>

void *thread_task(void *param)
{
	printf("Thread task\n");
	for(int i=0;i<5;i++)
		printf("%d ",i);
	return 0;
}

int main()
{
	pthread_attr_t attribute; //thread attribute
	pthread_t tid;
	
	void *stack;
	size_t size;

	size_t my_stacksize = 0x3000000;
	void *my_stack;

	pthread_attr_init(&attribute);

	pthread_attr_getstacksize(&attribute,&size); //get default stack size default stack size is 8 MB provided by pthread library
	pthread_attr_getstackaddr(&attribute,&stack); // get default stack address  default address is 000000 we are nothing in that because thread stack is not created

	printf("Default thread:\nAddress: %08x and default Size: %ld\n",stack,size);

	my_stack=(void*)malloc(my_stacksize); //getting free available stack address from memory

	pthread_attr_setstack(&attribute,my_stack,my_stacksize); // changing default property setting new stack size set address of my thread stack
				// set stack in new location which is given by my_stack and the size of the stack is my_stacksize

	pthread_create(&tid,&attribute,thread_task,NULL); 

	sleep(3);

	pthread_attr_getstack(&attribute,&stack,&size);

	printf("\nAfter changing default property:\nAddress: %08x and new Size: %ld\n",stack,size);

	return 0;

}