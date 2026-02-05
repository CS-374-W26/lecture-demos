// DON'T RUN THIS PROGRAM. IT WILL CRASH THE SERVER THAT YOU RUN IT ON.
// IF YOU FORKBOMB OS1, YOU'LL GET A WARNING THE FIRST TIME. IF YOU FORKBOMB
// ANY OTHER SERVER, THERE WILL BE NO WARNINGS---JUST A BIG PENALTY ON YOUR
// ASSIGNMENT 3 GRADE.

#include <unistd.h>
#include <stdio.h>

int main() {
	while(1) fork();
	/*
	while(some_condition) {
		// Hundreds of lines of code

		pid_t fork_result = fork();

		// A bunch more code
		if (fork_result == 0) {
			// Child process
			execvp("jfdsjafds");


			exit(1);
		} else {
			// Parent process
			
		}
	}
	*/
}
