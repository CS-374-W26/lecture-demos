#include <pthread.h>
#include <stdio.h>

struct thread_args {
	int thread_idx;
	double* volumes;
};

void* volume_of_sphere(void* args) {
	struct thread_args* casted_args = (struct thread_args*) args;

	double r = casted_args->thread_idx;
	double volume = 4.0 / 3.0 * 3.141592 * r * r * r;
	casted_args->volumes[casted_args->thread_idx] = volume;

	return NULL;
}

int main() {
	pthread_t threads[100] = {0};
	struct thread_args args[100] = {0};
	double volumes[100] = {0};
	for (int i = 0; i < 100; ++i) {
		args[i].thread_idx = i;
		args[i].volumes = volumes;
		// A void pointer is just a memory address of "something"
		pthread_create(&(threads[i]), NULL, volume_of_sphere, &args[i]);
	}

	

	


	for (int i = 0; i < 100; ++i) {
		void* foo_ret_val;
		pthread_join(threads[i], &foo_ret_val); // Wait on secondary thread to finish
	}

	printf("%lf\n", volumes[1] + volumes[99]);
}
