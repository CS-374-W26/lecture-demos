#include <stdio.h>

void change_me_pointer(int* ptr) {
	*ptr = 100;
}

void change_me(float array[], size_t size) {
	array[0] = 100.0;
}

struct person {
	int age;
};

int main() {
	int x;
	int* p = &x;

	*p = 5;

	int y;
	p = &y;

	*p = 10;

	printf("x = %d\n", x);
	printf("y = %d\n", y);

	char* my_pointer = NULL;
	// *my_pointer = 'A'; // Undefined behavior. my_pointer stores an arbitrary
			   // memory address inside it.
	
	if (my_pointer) {
		// This code will execute if and only if my_pointer is NOT
		// NULL
		*my_pointer = 'A';
	}

	float numbers[] = {3.14, 9.81, -1.7};

	printf("%p\n", my_pointer);
	printf("%p\n", numbers);
	printf("%p\n", &(numbers[0]));

	change_me(numbers);

	printf("%f\n", numbers[0]); // Prints 100.0

	change_me_pointer(&x);

	printf("%d\n", x); // Prints 100

	struct person joe;
	joe.age = 35;

	struct person* person_ptr = &joe;
	(*person_ptr).age = 21;
	person_ptr->age = 21;
}
