#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int fd = open("cool-words.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

	// Always call write() in a loop, unless you're truly just trying to
	// read one byte
	char my_string[256];
	sprintf(my_string, "%d %f superfluous\n", 37, 0.999);

	int keep_writing = 1;
	size_t total_bytes_written = 0;
	size_t total_bytes_to_write = strlen(my_string);
	while (total_bytes_written < total_bytes_to_write) {
		ssize_t n_bytes_written = write(
			fd,
			my_string + total_bytes_written,
			total_bytes_to_write - total_bytes_written
		);

		if (n_bytes_written > 0) {
			total_bytes_written += n_bytes_written;
		}
	}

	close(fd);
}
