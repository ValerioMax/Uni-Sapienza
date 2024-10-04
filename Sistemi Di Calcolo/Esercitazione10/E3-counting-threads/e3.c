#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "e3.h"

unsigned int *shared_array;

void *thread_product(void *data)
{
	thread_data_t *d = (thread_data_t *) data;
	shared_array[d->tid] = d->it * d->val;
	return(NULL);
}

unsigned int counting_threads(unsigned int th, unsigned int it, unsigned int val)
{
	shared_array = malloc(th * sizeof(unsigned int));
	pthread_t *threads = malloc(th * sizeof(pthread_t));
	thread_data_t *data = malloc(th * sizeof(thread_data_t));
	int rc;
	int i;
	int sum = 0;

	for (i = 0; i < th; i++)
	{
		data[i].it = it;
		data[i].val = val;
		data[i].tid = i;
		if (pthread_create(&threads[i], NULL, thread_product, &data[i]))
		{
			printf("Errore, codice %d\n",rc);
			exit(-1);
		}
	}
	for (i = 0; i < th; i++)
	{
		if (pthread_join(threads[i], NULL))
			exit(EXIT_FAILURE);
		sum += shared_array[i];
	}	
	free(shared_array);
	free(threads);
	free(data);

	return sum;
}