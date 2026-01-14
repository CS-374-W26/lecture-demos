#include <stdio.h>

int main() {
	// The primitive types in C that you really need to know
	// about
	// int: Integer
	// long int (long): Integer, but maybe bigger
	// float: Floating point number
	// double: Double-precision floating point number
	// char: Character
	
	// To create a variable in C:
	// type name; // Variable declaration
	int number_of_potatoes; // Variable declaration

	// To declare a variable means to state its existence.
	// Declaring a variable does NOT give it a value.
	
	// Attempting to use an undefined (uninitialized) variable
	// invokes undefined behavior (it causes the program to do
	// weird things at runtime)
	
	// To initialize a variable (assign a value to it):
	// name = value;
	number_of_potatoes = 43; // Variable initialization

	// Compound dlecaration + initialization
	// type name = value;
	int number_of_strawberries = 17;

	// Once a variable has been declared, it cannot be declared
	// again within the same scope
	
	printf(
		"The number of strawberries is %d\n",
		number_of_strawberries
	);
}
