////////////////////////////////////////////////////
//Program : Socket programming TCP		  //
//Author  : Kannan K D P			  //
//Date    : 12-03-2018				  //
//Filename: np6_tcp_ser.c			  //
////////////////////////////////////////////////////

//server machine



#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include <string.h>

int main(){
	struct sockaddr_in addr; // address location for the socket
	int server_fd,con,recvint,addrlen,new_socket;
	char message[]="Message successfully received";
	char recvmsg[100];
	
	addrlen=sizeof(addr);
	
	server_fd=socket( AF_INET ,SOCK_STREAM ,0); // socket creation
	

	if(server_fd < 0){ // socket creation failed
		printf("Socket error...\n");
		return 0;
	}
	
	// starting to define the settings for the socket address
	
	addr.sin_family = AF_INET;
	addr.sin_port	= 2500;
	addr.sin_addr.s_addr = INADDR_ANY;
	
	// settings end here
	
	bind(server_fd,(struct sockaddr *)&addr,sizeof(addr)); // for attaching the socket with the address location
	
	if(listen(server_fd,3) < 0){  // waiting for the client to connect to the server
		printf("Error in listening...\n");
	}
	else{
		printf("Listening for any connection pending...\n");
	}
	
	new_socket=accept(server_fd,(struct sockaddr *)&addr,(socklen_t *)&addrlen); // accepting the connection request
	
	if(new_socket < 0){
		printf("Error in accepting connection");
	}

	recv(new_socket,recvmsg,sizeof(recvmsg),0);
	
	printf("\nMessage from Client : %s\n\n",recvmsg);

	send(new_socket,message,sizeof(message),0);
	
	return 0;
	

}
