#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>


static struct sockaddr_un address;

int socket_send(int sock, int address_len){
	int i;
	char num[5]={0};
	printf("Start sending string !!!\n");

	for(i=0; i<=10; i++){
		sprintf(num, "%d", i);
		if(sendto(sock, num, sizeof(num), 0,(const struct sockaddr *)&address, address_len) < 0){
			return -1;
			break;
		}
		sendto(sock, ". message get!\n", 17, 0, (const struct sockaddr *)&address, address_len);
		sleep(1);
	}
	return 0;
}

int main(int argc, char *argv[]){
	int sockfd;
	int len;
	char string_send[256] = {0};

	sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);		                        //build the socket for client1

	address.sun_family = AF_UNIX;				                            //name the socket to match server
	strcpy(address.sun_path, "server_socket");

	len = sizeof(struct sockaddr_un);

	if(socket_send(sockfd, len) < 0){
		perror("Send Error: ");
	}
	return 0;
}