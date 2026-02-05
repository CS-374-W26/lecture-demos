#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
	int result = putenv("MY_COOL_ENVIRONMENT_VARIABLE=hello");
	pid_t fork_result = fork();
	// Here, we now have TWO processes that will run everything
	// below this line of code
	
	if (!fork_result) {
		// I am the child process.
		// execlp("ls", "ls", "../", "--color=auto", (char*) NULL);
		//char* arguments[] = {"ls", "fjdsajfdsaj", "--color=auto", NULL};
		//execvp("ls", arguments);
		
		char* value = getenv("MY_COOL_ENVIRONMENT_VARIABLE");
		printf("%s\n", value);

		pid_t my_pid = getpid();
		char* arguments[] = {"./die", NULL};
		execvp("./die", arguments);
	} else {
		// I am the parent process.
		// printf("I'm the parent process!\n");

		int exit_info;
		waitpid(fork_result, &exit_info, 0);

		if (WIFEXITED(exit_info)) {
			// This body will execute if the child process
			// returned SOMETHING out of its main function
			// (i.e., if it exited)
			int exit_status = WEXITSTATUS(exit_info);
			printf("The child process terminated with "
				"exit code %d\n", exit_status);
		} else if(WIFSIGNALED(exit_info)) {
			// This body will execute if the child process
			// was killed abruptly by a signal (e.g.,
			// segmentation fault)
			int signal_number = WTERMSIG(exit_info);
			printf("The child process was killed by a "
				"signal with code %d\n", signal_number);
		}
		
		// The following would simply check WHETHER the child
		// process has terminated instead of waiting for it
		// to terminate
		// pid_t wait_result = waitpid(fork_result, &exit_info, WNOHANG);
		// if (wait_result) {...}

		printf("The child process has finished!\n");
	}
}
