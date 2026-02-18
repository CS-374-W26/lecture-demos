#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int pipe_fds[2];
	int pipe_result = pipe(pipe_fds);
	if (pipe_result == -1) {
		printf("Error on pipe()!\n");
		exit(1);
	}

	pid_t fork_result_1 = fork();
	if (fork_result_1 == 0) {
		// This is the first child process
		close(pipe_fds[0]);

		dup2(pipe_fds[1], STDOUT_FILENO);

		execlp("ls", "ls", NULL);

		printf("Error on execlp()!\n");
		exit(1);
	} else if (fork_result_1 == -1){
		// This is the parent process, and fork failed.
	} else {
		// This is the parent process, and fork succeeded.
		pid_t fork_result_2 = fork();
		if (fork_result_2 == 0) {
			// This is the second child process
			close(pipe_fds[1]);

			dup2(pipe_fds[0], STDIN_FILENO);

			execlp("sort", "sort", NULL);
		
			printf("Error on execlp()!\n");
			exit(1);
		} else if (fork_result_2 == -1) {
			// This is the parent process, and fork failed
		} else {
			// This is the parent process, and fork succeeded
			close(pipe_fds[0]);
			close(pipe_fds[1]);
			// I will let the OS clean up the children when they're
			// done.
		}
	}

}
