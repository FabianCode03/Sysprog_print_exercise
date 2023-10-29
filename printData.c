#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

static int data = 0;

int main(void)
{
	pid_t id = fork();
	if (id < 0)
		perror("Error");
	else if (id == 0)
	{
		execl("myProgram", "myProgram", NULL);
	}
	else
	{
		sleep(5);
		for (int i = 0; i <= 10; ++i)
			data = data + i;

		printf("ID=%li, data=%d\n", (long)getpid(), data);

		int status;
		wait(&status);
	}
	return 0;
}
