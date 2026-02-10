#include <unistd.h>
#include <signal.h>
#include <stdio.h>

volatile sig_atomic_t state = 0;

// This signal handler is non-reentrant.
// Reentrant: 
void sigint_handler(int signo) {
	if (signo == SIGINT) {
		write(1, "Hello, World!\n", 14);
		if (state == 0) {
			state = 1;
		} else {
			state = 0;
		}
	} else if (signo == SIGTSTP) {
		printf("Ctrl+Z\n");
	}
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
	// sigdelset(&sigint_sa.sa_mask, SIGTSTP);
	sigint_sa.sa_flags = SA_RESTART;
	
	sigaction(SIGINT, &sigint_sa, NULL);
	sigaction(SIGTSTP, &sigint_sa, NULL);
	pause();
	pause();

	if (state == 0) {
		// It's okay to check the value of the state, but
		// not modify it, because that would make it
		// non-reentrant
	} else {
		
	}

	pause();



	struct sigaction sigint_ign = {0};
	sigint_ign.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sigint_ign, NULL);

	pause();
}
