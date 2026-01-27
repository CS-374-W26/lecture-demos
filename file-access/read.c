#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int fd = open("data.csv", O_RDONLY);

	// Always call read() in a loop, unless you're truly just trying to
	// read one byte
	char line[256] = {'\0'};
	int keep_reading = 1;
	size_t total_bytes_read = 0;
	while (keep_reading) {
		ssize_t n_bytes_read = read(
			fd,
			line + total_bytes_read,
			255 - total_bytes_read
		);

		if (n_bytes_read <= 0) {
			keep_reading = 0;
		} else {
			total_bytes_read += n_bytes_read;
		}
	}
	printf(line);

	close(fd);
}
