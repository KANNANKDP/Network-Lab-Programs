////////////////////////////////////////////////////
//Program : IPC using dual pipe			  //
//Author  : Kannan K D P			  //
//Date    : 29-01-2018				  //
//Filename: np3_dpipe.c			   	  //
////////////////////////////////////////////////////


#include <stdio.h>
#include <sys/types.h>
#include <string.h>

int main(){
	int pid;
	int fd1[2],fd2[2];
	int i;
	char s1[1000],s2[1000];
	int p1=pipe(fd1);
	int p2=pipe(fd2);
	printf("Enter the string which is to be written into the pipe1 by child\n");
	scanf("%s",s1);
	printf("Enter the string which is to be written into the pipe2 by parent\n");
	scanf("%s",s2);
	pid=fork();
	if(pid<0){
		printf("Some error has occured...");
		return 0;	
	}	
	if(p1!=-1 && p2!=-1){
		if(pid==0){
			printf("Child process is now executing\n");
			write(fd1[1],s1,sizeof(s1));
			close(fd2[1]);
			read(fd2[0],s2,sizeof(s2));
			close(fd1[0]);
			printf("The string from the pipe2 is %s %s\n",s2,s1);
		}
		if(pid>0){
			printf("Parent process is now executing\n");
			write(fd2[1],s2,sizeof(s2));
			close(fd1[1]);
			read(fd1[0],s1,sizeof(s1));
			close(fd2[0]);
			printf("The string from the pipe1 is %s %s\n",s1,s2);
			
			
		}
	}	
	else{
		printf("Some error....");
	}
	return 0;
	
	
}
