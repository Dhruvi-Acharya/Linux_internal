#include<stdio.h>
#include<signal.h>

void sighand(int no){
	printf("I am in sighandler\n");
}

void main(){
	sigset_t s_set; // holds multiple signal
	signal(2,sighand); //handling signal handler
	sigemptyset(&s_set);//clearing with empty initialization particular signal set by default not initialized
	sigaddset(&s_set,2); // 2 added to sigset adding particular signal
	perror("sig2");
	sigaddset(&s_set,4);
	perror("sig4");
	sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL); //blocking particular signal 2 and 4 
	perror("sigmask");
	printf("Send me signal one and see the effect now\n");
	getchar();
	getchar();
	sigprocmask(SIG_UNBLOCK,&s_set,NULL);
	printf("Now signals are unblocked\n");
	while(1);
}