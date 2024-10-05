#include "e2A.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



void run(int* v, int n, int (*f)(int i))
{
	int i;
	int res;

	for (i = 0; i < n; i++)
	{
		pid_t pid = fork();
		
		if (pid == -1)
		{
			perror("Errore fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			res = f(i);
			_exit(res);
		}
	}
	for (i = 0; i < n; i++)
	{
		int status;
		pid_t p = wait(&status);
		if (p == -1)
		{
			perror("Errore wait");
			exit(EXIT_FAILURE);
		}

		if (WIFEXITED(status))
			v[i] = WEXITSTATUS(status);
	}
}
