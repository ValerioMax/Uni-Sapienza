#include "e2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE    1024
#define MAX_TOKENS  64

void parse_data(char *argv[], char *buf)
{
	char *token;
	int i;

	token = strtok(buf, " \t\n");
	for (i = 0; token && i < MAX_TOKENS; i++)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	argv[i] = malloc(sizeof(void *));
	argv[i] = NULL;
}

void get_cmd_line(char* argv[])
{
	int res;
	char *buf;

	buf = malloc(MAX_LINE + 1);
	buf = fgets(buf, MAX_LINE, stdin);

	parse_data(argv, buf);

	free(buf);
	return ;
}

int do_shell(const char* prompt)
{
	char *argv[MAX_TOKENS];
	pid_t pid;
	int ex;
	int status;
	
	while (1)
	{
		printf("%s ", prompt);
		get_cmd_line(argv);
		if (argv[0])
		{
			if (!strcmp(argv[0], "quit"))
				return 1;
			else
			{
				pid = fork();
				if (pid == -1)
				{
					perror("Error fork\n");
					exit(EXIT_FAILURE);
				}
				if (pid == 0)
				{
					ex = execvp(argv[0], argv);
					if (ex == -1)
					{
						perror("unknown command\n");
						_exit(EXIT_FAILURE);
					}
					_exit(EXIT_SUCCESS);
				}
				pid = wait(&status); //va creata una variabile status ogni volta oppure va bene così?
			}
		}
	}
	return 1; //oppure return EXIT_SUCCESS; oppure exit(EXIT_SUCCESS);?
}
