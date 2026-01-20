#include <stdio.h>
#include <string.h>

int main() {
	// A C string is an array of characters whose contents end in one
	// or more null terminators. A null terminator is just a special
	// character.
	// char string[] = {'H', 'e', 'l', 'l', 'o', 0, '\0', 'f'};
	
	// This C string initialization syntax creates an array of characters
	// on the STACK, initialzes them to the characters of Hello, followed
	// by at least one null terminator.
	char string[] = "Hello";
	string[0] = 'J';
	
	// This C string initialization syntax creates an array of characters
	// in the READ-ONLY section of the DATA SEGMENT in memory, initializes
	// them to the characters of World, followed by at least one null
	// terminator, and then takes the base address of that array and stores
	// it in our pointer, string2.
	const char* string2 = "World";

	// I CANNOT do this:
	// string2[0] = 'J'; // I CANT DO THIS

	printf("%s\n", string2);

	printf("String length of string is: %d\n", strlen(string2));

	// To copy C strings, you must use strcpy()
	char string3[strlen(string) + 1];
	strcpy(string3, string);

	printf("%s\n", string3);

	if (strcmp(string, string3) == 0) {
		// They are the same!
		printf("string and string3 are the same!\n");
	}
}
