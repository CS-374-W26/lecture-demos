#include <pthread.h>
#include <stdio.h>

void* foo(void* thread_args) {
	printf("Hello, World!\n");
	return NULL;
}

int main() {
	pthread_t thread = {0};
	pthread_create(&thread, NULL, foo, NULL);

	

	printf("Goodbye, World!\n");



	void* foo_ret_val = NULL;
	pthread_join(thread, &foo_ret_val); // Wait on secondary thread to finish


}
