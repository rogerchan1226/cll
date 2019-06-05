#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>


int socket_recv(int sockfd){
	static struct sockaddr_un client_address;
	int string_num;
	char recv_buff[21]={0};
	socklen_t len = sizeof(&client_address);
	while(1){
		recvfrom(sockfd, recv_buff, sizeof(recv_buff), 0, 
				(struct sockaddr *)&client_address, &len);
		printf("%s", recv_buff);
	}
}

int main(int argc, char *argv[]){
	int server_sockfd;
	int server_len;
	struct sockaddr_un server_address;

	unlink("server_socket");												//remove old socket
	server_sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);							//create a new socket

	server_address.sun_family = AF_UNIX;									//
	strcpy(server_address.sun_path, "server_socket");						// name the socket just created
	server_len = sizeof(server_address);									//
	bind(server_sockfd, (struct sockaddr *) &server_address, server_len);	//

	socket_recv(server_sockfd);
	return 0;
}