#include "e1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
