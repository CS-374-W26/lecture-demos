#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

int main(void) {
	// Create socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	// Connect option 1, if you know the server's IP address:
	struct sockaddr_in server_address = {0};
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("192.168.0.1");
	server_address.sin_port = htons(80);
	int connect_result = connect(socket_fd, &server_address, sizeof(sockaddr_in));
	if (connect_result) {
		printf("Error on connect()\n");
		exit(1);
	}

	
}
