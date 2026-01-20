#include <string.h>
#include <stdio.h>

int main() {
	const char* mystring = "ab,cd/ef";
	char copy[strlen(mystring) + 1];
	strcpy(copy, mystring);
	
	printf("%s\n", copy);
	
	char* token1 = strtok(copy, ",/");
	char* token2 = strtok(NULL, ",/");
	char* token3 = strtok(NULL, ",/");

	printf("%s\n", token1);
	printf("%s\n", token2);
	printf("%s\n", token3);

	printf("%s\n", mystring);
}
