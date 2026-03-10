#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>

int main(void) {
	// Create listening socket
	int listening_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in bind_address = {0};
	bind_address.sin_family = AF_INET;
	bind_address.sin_addr.s_addr = INADDR_ANY;
	bind_address.sin_port = htons(51728);

	int bind_result = bind(listening_socket_fd, (struct sockaddr*) &bind_address, sizeof(struct sockaddr_in));
	if (bind_result) {
		printf("Error on bind()\n");
		exit(1);
	}


	int listen_result = listen(listening_socket_fd, 1000);
	if (listen_result) {
		printf("Error on listen()\n");
		exit(1);
	}
	
	
	while (1) {
		int comm_socket_fd = accept(listening_socket_fd, NULL, NULL);

		// Fork a new child process to handle the connection
		pid_t fork_result = fork();
		if (fork_result == 0) {
			// This is the child process
			char message[256];
			size_t total_bytes_read = 0;
			do {
				ssize_t bytes_read = recv(
					comm_socket_fd,
					message + total_bytes_read,
					256 - total_bytes_read,
					0
				);
				if (bytes_read == -1) {
					printf("Error on recv()\n");
					exit(1);
				}
				total_bytes_read += bytes_read;
			} while(message[total_bytes_read - 1] != '\0');
		
			// printf("Message from client: %s.\n", message);

			char* message1 = strtok(message, "@");
			char* message2 = strtok(NULL, "@");
			printf("Message 1: %s", message1);
			printf("Message 2: %s", message2);


			// Use key to encrypt plaintext

			// use send() to send the ciphertext back

			close(comm_socket_fd);

			exit(0);
		} else {
			// This is the parent process
			close(comm_socket_fd);
		}
	}

	


	

	close(listening_socket_fd);
}
