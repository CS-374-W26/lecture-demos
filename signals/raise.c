#include <stdio.h>
#include <signal.h>

int main() {
	raise(SIGINT);
	printf("Hello, World!\n");
}
