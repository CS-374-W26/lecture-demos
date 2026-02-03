#include <stdio.h>
#include <sys/stat.h>

int main() {
	struct stat file_metadata = {0};
	int result = stat("a.txt", &file_metadata);

	if (result) {
		printf("Error!\n");
	}

	printf("%ld\n", file_metadata.st_size);
}
