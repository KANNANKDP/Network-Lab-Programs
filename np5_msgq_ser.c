
////////////////////////////////////////////////////
//Program : IPC using message queue		  //
//Author  : Kannan K D P			  //
//Date    : 05-02-2018				  //
//Filename: np5_msgq_ser.c			  //
////////////////////////////////////////////////////

//server process

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>

int main(){

	int mid,k1,k2,k3,i;

	struct msgbuff{
		long msgtype;
		char msg[400];
	}s2,s2_key;

	mid=msgget(25,IPC_CREAT|0666); //creating message queue
	
	k1=msgrcv(mid,&s2,400,1,0);
	k2=msgrcv(mid,&s2_key,400,2,0);

	printf("The message from client is: %s\n",s2.msg);

	for(i=0;i<strlen(s2.msg);i++){
		s2.msg[i]=s2.msg[i]+2;
	}
	
	s2.msgtype=3;
	k3=msgsnd(mid,&s2,400,0);

	printf("The encoded msg is sent...\n");

	return 0;
	
}

