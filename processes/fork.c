#include <unistd.h>
#include <stdio.h>

int main() {
	pid_t fork_result = fork();
	// Here, we now have TWO processes that will run everything
	// below this line of code
	
	if (!fork_result) {
		// I am the child process.
		printf("I'm the child process!\n");
	} else {
		// I am the parent process.
		printf("I'm the parent process!\n");
	}
	printf("Hello, World!\n");


}
