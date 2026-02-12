#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = open("data.txt", O_RDONLY, 0000);

	pid_t fork_result = fork();

	if (fork_result == 0) {
		// I am the child
		char c;
		read(fd, &c, 1);
		printf("Child: %c\n", c);
		execlp("ls", "ls", "jfdsajfdsa", NULL);
		exit(0);
	} else {
		// I am the parent
		int exit_information;
		waitpid(fork_result, &exit_information, 0); // Wait for the child
		char c;
		read(fd, &c, 1);
		printf("Parent: %c\n", c);
	}
}
