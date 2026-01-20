#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
		if (strcmp(argv[i], "hello") == 0) {
			printf("Hello to you, too!\n");
		}
	}
}
