#include <pthread.h>
#include <stdio.h>

struct thread_args {
	int thread_idx;
	double* sum;
	pthread_mutex_t* mutex;
};

void* volume_of_sphere(void* args) {
	struct thread_args* casted_args = (struct thread_args*) args;

	double r = casted_args->thread_idx;
	double volume = 4.0 / 3.0 * 3.141592 * r * r * r;

	// Acquire the mutex's lock
	pthread_mutex_lock(casted_args->mutex);
	(*(casted_args->sum)) += volume;
	// release the mutex's lock
	pthread_mutex_unlock(casted_args->mutex);

	return NULL;
}

int main() {
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	pthread_t threads[100] = {0};
	struct thread_args args[100] = {0};
	double sum = 0.0;
	for (int i = 0; i < 100; ++i) {
		args[i].thread_idx = i;
		args[i].sum = &sum;
		args[i].mutex = &mutex;
		// A void pointer is just a memory address of "something"
		pthread_create(&(threads[i]), NULL, volume_of_sphere, &args[i]);
	}

	


	for (int i = 0; i < 100; ++i) {
		void* foo_ret_val;
		pthread_join(threads[i], &foo_ret_val); // Wait on secondary thread to finish
	}

	// pthread_mutex_lock(&mutex);
	printf("%lf\n", sum);
	// pthread_mutex_unlock(&mutex);
}
