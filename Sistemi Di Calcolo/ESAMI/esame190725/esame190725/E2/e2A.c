#include "e2A.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	is_in(char *s, char c, int start, int end)
{
	while (start < end)
	{
		if (s[start] == c) return 1;
		start++;
	}
	return 0;
}

int contains(char* s, char c, int n)
{
	int m = strlen(s) / n;
	int ok = 0;
	int i;

	if (m * n < strlen(s))
	{
		ok = is_in(s, c, n * m, strlen(s));
		if (ok)	return 1;
	}
	for (i = 0; i < n; i++)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("Errore fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			_exit(is_in(s, c, i * m, (i + 1) * m));
	}
	ok = 0;
	for (i = 0; i < n; i++)
	{
		int status;
		pid_t pid = wait(&status);
		if (pid == -1)
		{
			perror("Errore wait");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status) && WEXITSTATUS(status)) ok = 1;
	}
	return ok;
}




