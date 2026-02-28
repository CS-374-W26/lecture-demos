#include <pthread.h>
#include <stdio.h>

struct thread_args {
	int* printed_hello;
	pthread_cond_t* condition_variable;
	pthread_mutex_t* mutex;
};

void* print_world(void* args) {
	struct thread_args* casted_args = args;
	
	// Wait until the main thread has printed hello
	pthread_mutex_lock(casted_args->mutex);
	while (!(*(casted_args->printed_hello))) {
		pthread_cond_wait(casted_args->condition_variable, casted_args->mutex);
	}
	pthread_mutex_unlock(casted_args->mutex);

	// Print world!
	printf("World!\n");

	return NULL;
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

	// TODO Print hello, set printed_hello = 1 (requires locking mutex first),
	// and then signal the secondary thread to notify it that we have printed
	// hello
	printf("Hello, ");
	fflush(stdout);
	pthread_mutex_lock(&mutex);
	printed_hello = 1;
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&condition_variable);

	void* ret_val = NULL;
	pthread_join(thread, &ret_val);
}
