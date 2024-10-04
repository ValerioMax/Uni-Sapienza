/*
void trasla(char* text, int i)
{
	while (*(text + i))
	{
		*(text + i) = *(text + i + 1);
		i++;
	}
}

void drop_spaces(char* text)
{
	int i = 0;

	while (text[i])
	{
		if (text[i] == ' ')
			trasla(text, i);
		i++;
	}
}
*/

//oppure

void drop_spaces(char* text)
{
	char* s = text;

	while (*text)
	{
		if (*text == ' ')
			text++;
		else
			*s++ = *text++;
	}
	*s = '\0';
}
