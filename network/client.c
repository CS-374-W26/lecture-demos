#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

int main(void) {
	// Create socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	// Connect option 1, if you know the server's IP address:
	/*
	struct sockaddr_in server_address = {0};
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(80);
	int connect_result = connect(socket_fd, (struct sockaddr*) &server_address, sizeof(struct sockaddr_in));
	if (connect_result) {
		printf("Error on connect()\n");
		exit(1);
	}
	*/

	// Connect option 2, if you DON'T know the server's IP address but DO
	// know its hostname
	struct addrinfo hints = {0};
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	struct addrinfo* linked_list = NULL;
	int getaddrinfo_result = getaddrinfo("localhost", "51728", &hints, &linked_list);
	if (getaddrinfo_result) {
		printf("Error on getaddrinfo()\n");
		exit(1);
	}

	struct addrinfo* itr = linked_list;
	while (itr) {
		int connect_result = connect(socket_fd, itr->ai_addr, itr->ai_addrlen);
		if (!connect_result) {
			break;
		}
		itr = itr->ai_next;
	}

	if (!itr) {
		printf("Failed to connect to ANY of the servers!\n");
		exit(1);
	}

	freeaddrinfo(linked_list);

	const char* message = "Hello";
	size_t bytes_to_write = strlen(message) + 1;
	ssize_t total_bytes_written = 0;
	while (total_bytes_written < bytes_to_write) {
		ssize_t bytes_written = write(
			socket_fd,
			message + total_bytes_written,
			bytes_to_write - total_bytes_written
		);
		if (bytes_written == -1) {
			printf("Error on write()\n");
			exit(1);
		}
		total_bytes_written += bytes_written;
	}

	

	close(socket_fd);
}
