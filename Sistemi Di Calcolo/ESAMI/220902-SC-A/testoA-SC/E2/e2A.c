#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getStudents(const char * filename, student * in_list, int min_mark)
{
	FILE *f = fopen(filename, "w");
	if (!f) return ;

	student *temp = in_list;

	while(temp)
	{
		if (temp->mark >= min_mark)
			fprintf(f, "%s %s - %d\n", temp->surname, temp->name, temp->mark);
		temp = temp->next;
	}
	fclose(f);
	return ;
}
