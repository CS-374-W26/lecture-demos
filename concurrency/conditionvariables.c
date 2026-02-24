#include <pthread.h>
#include <stdio.h>

struct thread_args {
	int* printed_hello;
	pthread_cond_t* condition_variable;
	pthread_mutex_t* mutex;
};

void* print_world(void* args) {
	struct thread_args* casted_args = args;
	
	// TODO Wait until the main thread has printed hello
}

int main(void) {
	pthread_cond_t condition_variable;
	pthread_cond_init(&condition_variable, NULL);
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	int printed_hello = 0;

	pthread_t thread = {0};
	struct thread_args args = {0};
	args.printed_hello = &printed_hello;
	args.condition_variable = &condition_variable;
	args.mutex = &mutex;
	pthread_create(&thread, NULL, print_world, &args);

	// TODO Print hello, and then signal the secondary thread to notify it
	// that we have printed hello
}
