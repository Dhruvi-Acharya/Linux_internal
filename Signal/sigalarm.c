#include<signal.h>

void sighand(int signum){
	printf("I have to wakeup my boss now\n");
	//alarm(5);
}

main(){
	signal(SIGALRM,sighand);
	/*if(signal(SIGINT,sighand)){
		printf("signal generated\n");
	}*/
	alarm(5);
	while(1){

	}
}