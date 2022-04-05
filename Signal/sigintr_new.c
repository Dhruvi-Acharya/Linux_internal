#include<signal.h>

void sighand(int signum){
	printf("I have to wakeup my boss now\n");

	if(signal(SIGINT,sighand)){
		printf("signal generated\n");
	}
	//alarm(5);
	exit(0);
}

main(){
	signal(SIGINT,sighand);
	/*if(signal(SIGINT,sighand)){
		printf("signal generated\n");
	}*/
	//alarm(5);
	for(int i=0;;i++){
		printf("%d\n",i);
		sleep(1);
	}
}