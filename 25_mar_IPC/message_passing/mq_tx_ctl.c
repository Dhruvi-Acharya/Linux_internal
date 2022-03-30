#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf{
	long mtype;
	char data[512];
};

int main(int argc, char *argv[]){
	struct msgbuf v;
	int id;

	struct msqid_ds buf;

	id = msgget(55,IPC_CREAT|0644);

	printf("id: %d\n",id);

	v.mtype = atoi(argv[1]); // argument 1 is type of message converting ascii to int

	strcpy(v.data,argv[2]); // argument 2 is message

	msgsnd(id,&v,strlen(v.data)+1,0); // Flag_IPC_NOWAIT

	msgctl(id,IPC_STAT,&buf); 

	printf("here are the details of the queue\n");
	printf("no of msg's in q %hi\n",buf.msg_qnum);

	printf("max no of bytes in q %hi\n",buf.msg_qbytes);

	return 0;
}