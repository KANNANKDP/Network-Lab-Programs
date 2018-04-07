////////////////////////////////////////////////////
//Program : Socket programming TCP		  //
//Author  : Kannan K D P			  //
//Date    : 12-03-2018				  //
//Filename: np6_tcp_ser.c			  //
////////////////////////////////////////////////////

//client machine



#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>

int main(){
	struct sockaddr_in addr; // address location for the socket
	int client_fd,con,recvint;
	char message[100],recvmsg[100];
	
	client_fd=socket(AF_INET,SOCK_STREAM,0); // socket creation
	
	printf("Enter the message which is to be sent to the server: "); //message which is to be sent to the server
	scanf("%s",message);
	
	if(client_fd<0){ // socket creation failed
		printf("Socket error...\n");
		return 0;
	}
	
	// starting to define the settings for the socket address
	
	addr.sin_family = AF_INET;
	addr.sin_port	= 2500;
	addr.sin_addr.s_addr = INADDR_ANY;
	
	// settings end here
	
	con=connect(client_fd,(struct sockaddr *)&addr,sizeof(addr)); // establishing connection with the server using socket.
	
	if(con < 0){ // error in connection
		printf("Error in establishing connection...\n");
	}
	
	send(client_fd,message,sizeof(message),0); // send message to server
	
	recvint=recv(client_fd,recvmsg,sizeof(recvmsg),0); // receive success message from server
	
	printf("\n Message from server : %s \n",recvmsg); 
	
	
	
	return 0;

}
