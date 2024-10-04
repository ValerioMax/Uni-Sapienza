int substring(const char* s, const char* sub)
{
	while (*s && *sub)
	{
		if (*s != *sub)
			return 0;
		s++;
		sub++;
	}
	if (*sub)
		return 0;
	return 1;
}

int count_substrings(const char* s, const char* sub)
{
	int counter = 0;

	if (*sub == '\0')
		return 1;
	while (*s)
	{
		counter += substring(s, sub);
		s++;
	}
	return counter;
}