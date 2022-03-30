#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

//# define KEY 8979

typedef struct {
	long mtype;
	char data[100];
}msg;

int main(int argc, char *argv[]){

	msg m1,m2;;
	int id,i;

	id = msgget(55,IPC_CREAT|0644);

	m1.mtype = 10;

	for(i=0;i<100;i++){
		m1.data[i]='a';
	}

	m2.mtype = 20;

	for(i=0;i<100;i++){
		m2.data[i]='b';
		//m2.mtype=20;
	}

	i = msgsnd(id,&m1,sizeof(msg),0);
	printf("return value of msgsnd of As: %d\n",i);

	i = msgsnd(id,&m2,sizeof(msg),0);
	printf("return value of msgsnd of Bs: %d\n",i);
	//printf("id: %d\n",id);

	//v.mtype = atoi(argv[1]); // argument 1 is type of message converting ascii to int

	//strcpy(v.data,argv[2]); // argument 2 is message

	//msgsnd(id,&v,strlen(v.data)+1,0); // Flag_IPC_NOWAIT

	

	return 0;
}