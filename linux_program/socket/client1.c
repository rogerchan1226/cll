#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>


int socket_send(){
	printf("Start sending string !!!");
	for(int i=0; i++; i=10){

	}
}

int main(int argc, char *argv[]){
	int sockfd;
	int len;
	struct sockaddr_un address;
	char string_send[256] = {0};

	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);		                        //build the socket for client1

	address.sun_family = AF_UNIX;				                            //	{
	strcpy(address.sun_path, "server_socket");		                        //		name the socket to match server
	len = sizeof(address);							                        //	}
		
	if(connect(sockfd, (struct sockaddr *)&address, len) < 0){              //connect to server socket
		perror("oops: client");
		return -1;
	}

	socket_send();
	return 0;
}