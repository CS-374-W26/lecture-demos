#include <stdio.h>

double add(double a, double b) {
	// Function body
	
	return a + b;
}

void say_hello(int n) {
	for (int i = 0; i < n; ++i) {
		printf("Hello!\n");
	}
}

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

	// In real life, 1 / 2 is 0.5
	// In C,         1 / 2 is 0
	
	// Using the wrong format specifier results in
	// undefined behavior
	printf("999 / 1000 = %d\n", 999.0 / 1000.0);

	number_of_strawberries += 3;
	
	number_of_strawberries++;
	number_of_strawberries--;

	++number_of_strawberries;
	--number_of_strawberries;

	printf("%d\n", ++number_of_strawberries);


	// Two ways to type-cast
	// 1. Implicit type casting
	number_of_strawberries = 3.9;

	float pi = 7;

	// Casting floating point value -> integral value == truncation
	// Casting integral value -> floating point value == tack a .0 onto it

	// 2. Explicit type casting
	int x = 3;
	int y = 5;
	printf("%f\n", (double) x / (double) y);

	// Relational operators in C:
	// <, <=, >, >=, ==, !=
	
	// Logical operators in C:
	// || (logical or, with short circuiting)
	// && (logical and, with short circuiting)
	// ! (logical not)
	//
	// | (logical or, without short circuiting)
	// & (logical and, without short circuiting)
	
	if (number_of_strawberries >= 2 && number_of_strawberries <= 5) {
		// If statement body
		printf("Hello\n");
	} else if (number_of_strawberries < -1) {

	} else {

	}

	int counter;
	counter = 0;
	while (counter < 10) {
		// Some code here

		++counter;
	}

	counter = 0;
	do {
		// Some code here

		++counter;
	} while(counter < 10);


	// Three things in your for loop header:
	// 1. Initialization statement
	// 2. Condition
	// 3. Post statement
	for (int i = 0; i < 10; ++i) {
		// For loop body
		printf("%d\n", i);
	}

	// In C, loosely, a scope is dictated by curly braces

	// Scope dictates
	// 1. where symbols are accessible
	// 2. when automatic variables are freed (storage duration)

	// An automatic variable is a variable with automatic storage duration
	// Basically, function-locals
	
	// For the curious reader, look up variable shadowing in C
	
	// Automatic arrays have certain restrictions:
	// 1. Homogeneous
	// 2. They can't be resized. Common trick is to oversize them so
	// 	that you have "extra space" to work with.
	
	// To declare an automatic array:
	char word[4];

	// To access elements within an array:
	word[0] = 'J';
	word[1] = 'u';
	word[2] = 'm';
	word[3] = 'p';

	for (int i = 0; i < 4; ++i) {
		printf("%c", word[i]);
	}
	printf("\n");
	
	// Buffer overflows and overreads:
	printf("%c", word[4]); // Undefined behavior
	word[4] = 's'; // Undefined behavior

	// Aggregate initialization
	float numbers[5] = {3.14, 9.81, -1.5, 1.5};

	char string[100] = {0};

	// The main function is special. The main function has an int return
	// type. If you don't return any values out of the main function,
	// when the closing curly brace is it, it automatically returns 0.
	// The return value of the main function specifies the process's
	// exit code.
}
