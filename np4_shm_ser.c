////////////////////////////////////////////////////
//Program : IPC using shared memory		  //
//Author  : Kannan K D P			  //
//Date    : 05-02-2018				  //
//Filename: np4_shm_ser.c			  //
////////////////////////////////////////////////////

//server process

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main(){

	int id,sum=0,i=0;
	char expr[400];
	int sid;
	char *shmaddr;
	
	printf("Server process is executing\n");

	sid=shmget(25,400, IPC_CREAT | 0666 );
	shmaddr=shmat(sid,NULL,0);
	
	sscanf(shmaddr , "%s" , expr);
	
	for(i=0;expr[i]!='\0';i++){
		if(expr[i]=='+'){
			continue;
		}
		sum+=expr[i]-48;
		
	}
	
	printf("The sum of 4+3+2 is %d",sum);
	
	shmdt(shmaddr);


	return 0;
	
}

