#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int examStats(const char* fname, int * min, int * max, float * avg)
{
	FILE *f = fopen(fname, "r");
	if (!f)	goto CLEANUP;
	//se file vuoto
	fseek(f, 0, SEEK_END);
	if (ftell(f) == 0) goto CLEANUP;
	fseek(f, 0, SEEK_SET);

	char *buf = malloc(257);
	char *token;
	char *grade_s = malloc(3);
	int num_ok = 0;
	int grade = 0;
	*min = 31;
	*max = 0;
	*avg = 0;


	while (!feof(f))
	{
		buf = fgets(buf, 256, f);
		token = strtok(buf, "-");
		token = strtok(NULL, "-");
		token = strtok(NULL, "-");
		grade = atoi(strcpy(grade_s, token));
		if (grade >= 18)
		{
			*avg += grade;
			num_ok++;
			if (grade < *min)
				*min = grade;
			else if (grade > *max)
				*max = grade;
		}
	}
	if (num_ok > 0)
		*avg /= num_ok;
	if (*min == 31)
		*min = 0;

	free(buf);
	free(grade_s);
	fclose(f);
	return num_ok;

CLEANUP:
	int old_errno = errno;
	*min = 0;
	*max = 0;
	*avg = 0;
	if (!f) return -1;
	fclose(f);
	errno = old_errno;
	return 0;
}
