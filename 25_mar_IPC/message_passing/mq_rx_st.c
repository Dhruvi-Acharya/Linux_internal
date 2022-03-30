#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>//1
#include<sys/types.h>//1
#include<sys/msg.h>//1

typedef struct {
	long mtype;
	char data[100];
}msgbuf;

int main(int argc, char *argv[]){
	int id,i;
	msgbuf v1,v2;

/*	if(argc!=2){
		printf("usage: ./mq_rx type\n");
		printf("Example: mq_rx 5\n");
		return 0;
	}*/

	id = msgget(55,IPC_CREAT|0644); // msgget(key,permission)

	if(id<0){
		perror("msgget");
		return 0;
	}

	i = msgrcv(id,&v1,sizeof(msgbuf),10,0); //./rx 44

	for(i=0;i<100;i++)
		printf("%c",v1.data[i]);

	printf("\n");

	i = msgrcv(id,&v2,sizeof(msgbuf),20,0); //./rx 44

	for(i=0;i<100;i++)
		printf("%c",v2.data[i]);

	printf("\n");

	return 0;
}