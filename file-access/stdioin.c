#include <stdlib.h>
#include <stdio.h>

int main() {
	// Open the text file
	FILE* file_stream = fopen("data.csv", "r");
	if (!file_stream) {
		printf("Error! Failed to open the file!\n");
	}

	// getline()
	// fgets()
	char* line = NULL;
	size_t n = 0;
	ssize_t line_len = getline(&line, &n, file_stream);


	line[line_len - 1] = '\0';

	printf("%s\n", line);

	
	free(line);
	fclose(file_stream);
}
