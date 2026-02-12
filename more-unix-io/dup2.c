#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int out_fd = open("out.txt", O_WRONLY | O_CREAT, 0644);
	int in_fd = open("in.txt", O_RDONLY, 0000);
	dup2(out_fd, 1);
	dup2(in_fd, 0);
	char* line = NULL;
	size_t n = 0;
	getline(&line, &n, stdin);

	printf(line);
	
	close(out_fd);
	close(in_fd);

	free(line);
}
