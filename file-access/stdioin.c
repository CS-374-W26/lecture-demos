#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	// The file offset is the "imaginary" cursor that starts at the topleft
	// of the file when it's first opened.
	
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


	char line2[256];
	char* result = fgets(line2, 256, file_stream);
	if (!result) {
		printf("Error!\n");
	}
	line2[strlen(line2) - 1] = '\0';

	printf("%s\n", line2);
	

	
	free(line);
	fclose(file_stream);
}
