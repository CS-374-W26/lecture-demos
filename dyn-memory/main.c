#include <stdlib.h>
#include <stdio.h>

float* append(float* array, float new_value, size_t cur_size) {
	float* result = (float*) realloc(array, (cur_size + 1) * sizeof(float));
	result[cur_size] = new_value;
	return result;
}

int main() {
	
	// To allocate memory on the heap, use malloc()
	float* array = (float*) malloc(20 * sizeof(float));
	
	array[0] = 3.14;

	for (int i = 0; i < 20; ++i) {
		array[i] = 1.0;
	}

	array = append(array, 7.1, 20);

	// If you forget to do this / your program somehow skips this tep
	// (e.g., it's in an if statement that doesn't fire), then you have
	// a memory leak.
	free(array);

	// After calling free(ptr), ptr is then a dangling pointer.
	// A dangling pointer is a pointer that points to deleted memory.

	// Dereferencing a dangling pointer is referred to as a
	// "use-after-free" error. It invokes undefined behavior.
	
	// Setting your pointer to NULL is a good way to avoid use-after-free
	// / get rid of dangling pointers
	array = NULL;


}
