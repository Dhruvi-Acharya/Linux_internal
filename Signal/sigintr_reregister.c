#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int signum){
	printf("inside handler function\n");
	signal(SIGINT,SIG_DFL); // re register signal handler for default action
}

int main(){
	signal(SIGINT,sig_handler);
	for(int i=1;;i++){
		printf("%d: inside main function\n",i);
		sleep(1);
	}

	return 0;
}