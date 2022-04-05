#include<stdio.h>
#include<signal.h>

void sighand(int signum){
	printf("interrupt signal rec'd... but no termination on ctrl+c \n");
}

main(){
	int i;
	signal(SIGINT,sighand);
	//signal(SIGINT,SIG_DEL);
	//while(1){}

	for(i=0;;i++){
		printf("%d\n",i);
		sleep(i);
	}
}