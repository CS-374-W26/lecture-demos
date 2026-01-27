#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	// The file offset is the "imaginary" cursor that starts at the topleft
	// of the file when it's first opened.
	
	// Open the text file
	FILE* file_stream = fopen("cool-words.txt", "a");
	if (!file_stream) {
		printf("Error! Failed to open the file!\n");
	}

	fprintf(file_stream, "%d %f superfluous\n", 21, -7.92);

	fclose(file_stream);
}
