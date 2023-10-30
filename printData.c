#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>

static int data = 0;

void *thread_function(void *unused)
{
	(void)unused;
	// sleep(5);
	for (int i = 1; i <= 10; ++i)
	{
		data = data + i;
	}

	printf("Threat_ID=%lu, data=%d\n", pthread_self(), data);
	return NULL;
}

int main(void)
{
	pthread_t newThread;

	errno = pthread_create(&newThread, NULL, thread_function, NULL);
	if (errno)
	{
		perror("Fehler in pthread_create()");
		// exit(EXIT_FAILURE);
	}

	// sleep(5);
	for (int i = 0; i <= 10; ++i)
		data = data + i;

	printf("Threat_ID=%lu, data=%d\n", pthread_self(), data);

	pthread_join(newThread, NULL);

	return 0;
}
