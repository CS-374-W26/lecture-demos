#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sigint_handler(int signo) {
	write(1, "Hello, World!\n", 14);
}

int main() {
	// A process's signal disposition may be one of three
	// things
	// 1. SIG_DFL (default)
	// 2. SIG_IGN (ignore)
	// 3. Having a signal handler

	struct sigaction sigint_sa = {0};
	sigint_sa.sa_handler = sigint_handler;
	sigfillset(&sigint_sa.sa_mask);
	sigint_sa.sa_flags = SA_RESTART;
	
	sigaction(SIGINT, &sigint_sa, NULL);

	pid_t fork_result = fork();

	if (fork_result == 0) {
		// This is the child process

		execlp("ls", "ls", "jfdsajfds", NULL);

		exit(1);
	} else {
		// The parent process

	}
}
