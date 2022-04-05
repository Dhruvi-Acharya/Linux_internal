// which particluar is blocked
#include<stdio.h>
#include<signal.h>

void check_blocked_sigs(){
	int i,res;
	sigset_t s;
	sigprocmask(SIG_BLOCK,NULL,&s); 

	for(i=1;i<5;i++){
		res = sigismember(&s,i);
		if(res)
			printf("signal %d is pending\n",i);
		else
			printf("signal %d is not pending\n",i);
	}
}

void sighand(int no){
	printf("i am in sighandler\n");
}

void main(){
	sigset_t s_set,s;
	signal(2,sighand);
	sigemptyset(&s_set);
	sigaddset(&s_set,2);

	//sigaddset(&s_set,4);

	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);
	
	printf("Send me signal one and see the effect now\n");
	getchar();
	getchar();

	sigpending(&s);

	check_blocked_sigs();
	getchar();
	sigprocmask(SIG_UNBLOCK,&s_set,NULL);

	printf("Now signals are unblocked\n");
	while(1);
	//check_blocked_sigs();
}