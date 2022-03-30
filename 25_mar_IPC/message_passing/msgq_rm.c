#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

int main(){
	int qid;
	struct msqid_ds buf;

	qid = msgget(55,IPC_CREAT|0644);

	printf("id: %d\n",qid);

	msgctl(qid,IPC_RMID,NULL); 

	return 0;
}