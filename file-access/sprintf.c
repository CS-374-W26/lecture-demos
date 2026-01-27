#include <stdio.h>
#include <string.h>

int main() {
	char my_string[256];
	sprintf(my_string, "Hello, World! %d %.2f\n", 315, 7.2816);

	printf(my_string);
}
