#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
	alarm(5);
	pause();
	printf("Hello, World!\n");
}
