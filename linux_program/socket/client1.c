#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>




int main(){
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch = 'A';

	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);		//build the socket for client1

	address.sun_family = AF_UNIX;				    //	{
	strcpy(address.sun_path, "server_socket");		//		name the socket to match server
	len = sizeof(address);							//	}
	
	result = connect(sockfd, (struct sockaddr *)&address, len);		//connect to server socket

	if(result == -1){
		perror("oops: client1");
		exit(0);
	}

	write(sockfd, &ch, 1);		//to write by sockfd
	read(sockfd, &ch, 1);		//to read  by sockfd
	printf("char from server = %c\n", ch);
	close(sockfd);
	exit(0);
}