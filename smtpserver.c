///////////////////////////////////////////////////////////////
// Program name : SMTP using UDP			     //
// File name    : smtpserver.c                               //
// Author	: Kannan K D P , SCT15CS033                  //
// Date		: 26/03/2018				     //
///////////////////////////////////////////////////////////////			  		 
//server machine
//including libraries
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>
#include<arpa/inet.h>

int main(int argc, char const *argv[])//opening main
{ //declaring variables
	struct sockaddr_in serv_addr,client_addr;
	char to[100],from[100],sub[100],msg[100],buf[100];
	int sock,i,flag=0,s,t,f,m,slen=sizeof(client_addr),pos;

	strcpy(buf,"Received at server");	

	sock=socket(AF_INET, SOCK_DGRAM, 0);		//SOCKET CREATION
	if(sock<0)
		printf("\nSocket Creation Error\n");

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = 7889;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	bind(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));	//binds socket to address and port no specified

	while(1)
	{
		flag=0;
		printf("\nListening\n");
		//receiving message
		t=recvfrom(sock, to, sizeof(to), 0, (struct sockaddr *) &client_addr,&slen);
		f=recvfrom(sock, from, sizeof(from), 0, (struct sockaddr *) &client_addr,&slen);
		s=recvfrom(sock, sub, sizeof(sub), 0, (struct sockaddr *) &client_addr,&slen);
		m=recvfrom(sock, msg, sizeof(msg), 0, (struct sockaddr *) &client_addr,&slen);
		//verifying domain
		for(i=0;to[i]!='\0';i++)
		 	if(to[i]=='@'){
				flag=1;
				pos=i+1;}
		
		if(flag==1)		//printing details if domain verified
		{
			printf("\nTo:%s\n",to);
			printf("Domain verified:\t<%s>\t\tDomain:",to);
			for(i=pos;to[i]!='\0';i++){
				printf("%c",to[i]);}
			printf("\nFrom:%s",from);
			printf("\nSub:%s",sub);
			printf("\nMessage:%s",msg);
		
			s=sendto(sock , buf , sizeof(buf) , 0 , (struct sockaddr*) &client_addr, sizeof(client_addr));
			if(s<0)
				printf("\nSending Error");
			else
				printf("\nSent");	
		}	
		else
			printf("validation error");

		
	}
}//closing main

