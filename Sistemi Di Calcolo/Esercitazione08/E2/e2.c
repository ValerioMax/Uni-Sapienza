#include "e2.h"
//30+2+5
#include <stdio.h>
struct booking *new_table(char *surname, int number, char *hour, struct booking *next)
{
	struct booking *t = (struct booking *) malloc(sizeof(struct booking));
	t->surname = malloc(sizeof(char) * strlen(surname));
	t->time = malloc(sizeof(char) * strlen(hour));

	memcpy(t->surname, surname, strlen(surname));
	memcpy(t->time, hour, strlen(hour));

	t->places = number;
	t->next = next;
	return t;
}

void get_surname(char *surname, const char *data)
{
	int i = 0;

	while (data[i] != '_' && i < 30)
	{
		surname[i] = data[i];
		i++;
	}
	surname[i] = '\0';
}

void getBookingsAfterTime(struct booking ** list, const char * data, int size, const char * time)
{
	int i = 0;
	char *surname = malloc(31);
	int	number;
	char *hour = malloc(5);
	int val1 = 0;
	int val2 = (time[0] - '0')*10*60 + (time[1] - '0')*60 + (time[3] - '0')*10 + (time[4] - '0');

	struct booking * temp = *list;

	for (; i < size; i += 37)
	{
		get_surname(surname, data + i);

		number = *(data + i + 30) - '0' + *(data + i + 31) - '0';

		memcpy(hour, data + i + 32, 5);
		hour[5] = '\0';

		val1 = (hour[0] - '0')*10*60 + (hour[1] - '0')*60 + (hour[3] - '0')*10 + (hour[4] - '0');
		printf("%d, %d\n", val1, val2);

		if (val1 >= val2)
		{
			struct booking *t = new_table(surname, number, hour, NULL);

			if (!temp)
			{
				temp = t;
				*list = t;
			}
			else
			{
				temp->next = t;
				temp = temp->next;
			}
				
		}	
	}
	free(surname);
	free(hour);
	temp = *list;
	for (; temp; temp = temp->next)
		printf("%s, %d, %s\n", temp->surname, temp->places, temp->time);
}