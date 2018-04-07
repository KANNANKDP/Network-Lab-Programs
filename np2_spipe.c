////////////////////////////////////////////////////
//Program : IPC using single pipe		  //
//Author  : Kannan K D P			  //
//Date    : 29-01-2018				  //
//Filename: np2_spipe.c			   	  //
////////////////////////////////////////////////////


#include <stdio.h>
#include <sys/types.h>
#include <string.h>

int main(){
	int pid,i=0;
	int fd[2];
	char s[1000];
	int p=pipe(fd);
	pid=fork();
	if(pid<0){
		printf("Some error has occured...");
		return 0;	
	}	
	if(p!=-1){
		if(pid==0){
			printf("Child process is now executing\n");
			printf("Enter the string which is to be encoded\n");
			scanf("%s",s);
			i=0;		
			while(s[i]!='\0'){
				if(s[i]=='y'){
					s[i++]='a';
					continue;
				}
				if(s[i]=='z'){
					s[i++]='b';
					continue;
				}
				s[i]=s[i]+2;
				i++;
			}	
			write(fd[1],s,sizeof(s));
		}
		if(pid>0){
			printf("Parent process is now executing\n");
			read(fd[0],s,sizeof(s));
			printf("The encoded string is %s\n",s);
			i=0;
			while(s[i]!='\0'){
				if(s[i]=='a'){
					s[i++]='y';
					continue;
				}
				if(s[i]=='b'){
					s[i++]='z';
					continue;
				}
				s[i]=s[i]-2;
				i++;
			}
			printf("The decoded string is %s\n",s);
			
		}
	}	
	else{
		printf("Some error....");
	}
	return 0;
}

