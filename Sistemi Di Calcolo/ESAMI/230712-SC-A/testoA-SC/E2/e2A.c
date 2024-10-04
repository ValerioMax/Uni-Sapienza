#include "e2A.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int conta_vocali(const char* s)
{
	int count = 0;
	char c;

	while (*s)
	{
		c = tolower(*s);
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			count++;
		s++;
	}
	return count;
}

int vowelcount(const char** s, int n)
{
	if (!s || !n) return -1;

	int i;
	int num_vocali = 0;
	int tot_vocali = 0;
	int status;

	//figli partono tutti e calcolano
	for (i = 0; i < n; i++)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("Error fork");
			exit(-1);
		}		
		if (pid == 0) //sono nel figlio
		{
			num_vocali = conta_vocali(s[i]);
			_exit(num_vocali);
		}
	}
	//genitore raccoglie i risultati
	for (i = 0; i < n; i++)
	{
		int res = wait(&status);
		if (WIFEXITED(status))
			tot_vocali += WEXITSTATUS(status);
	}

	return tot_vocali;
}