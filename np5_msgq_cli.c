
////////////////////////////////////////////////////
//Program : IPC using message queue		  //
//Author  : Kannan K D P			  //
//Date    : 05-02-2018				  //
//Filename: np5_msgq_cli.c			  //
////////////////////////////////////////////////////

//client process

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>

int main(){
	
	int k1,k2,k3,mid,i;

	struct msgbuff{
		long msgtype;
		char msg[400];
	}s1,s1_key;
	
	s1.msgtype=1;
	s1_key.msgtype=2;

	printf("Enter the message which is to be sent to the server: ");
	scanf("%s",s1.msg); //message input

	printf("Enter the encode key: ");
	scanf("%s",s1_key.msg); //key input

	mid=msgget(25,IPC_CREAT|0666); //creating message queue
	
	k1=msgsnd(mid,&s1,400,0);
	k2=msgsnd(mid,&s1_key,400,0);

	sleep(0.5);

	k3=msgrcv(mid,&s1,400,3,0);
	
	printf("The message from server : %s\n",s1.msg);

	return 0;
	
}

