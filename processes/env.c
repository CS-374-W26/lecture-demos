#include <stdlib.h>
#include <stdio.h>

int main() {
	char* username = getenv("USER");
	printf("Hello, %s\n", username);

	int result = putenv("MY_COOL_ENVIRONMENT_VARIABLE=hello");
	if (result) {
		printf("Error! Failed to allocate new environment variable\n");
	}

	char* value = getenv("MY_COOL_ENVIRONMENT_VARIABLE");
	printf("%s\n", value);
}
