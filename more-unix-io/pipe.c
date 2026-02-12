#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int pipe_fds[2];
	int pipe_result = pipe(pipe_fds);
	if (pipe_result) {
		printf("Error on pipe!\n");
		exit(1);
	}

	pid_t fork_result = fork();

	// Pipes are for unidirectional (one-way) communication. 

	if (fork_result == 0) {
		// This is the child process
		// The child process is going to be reading, so we don't need
		// the writing end of the pipe here. So we should close its fd.
		close(pipe_fds[1]);

		char message[256] = {0};
		read(pipe_fds[0], message, 255);

		printf("%s\n", message);

		close(pipe_fds[0]);
	} else {
		// This is the parent process
		// The parent process is going to writing, so we don't need
		// the reading end of the pipe here.
		close(pipe_fds[0]);

		const char* message = "Have a good day at school!";
		write(pipe_fds[1], message, strlen(message));
		close(pipe_fds[1]);
	}
}
