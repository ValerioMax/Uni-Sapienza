char *my_strcat(char *dest, const char *src)
{
	int i = 0;
	int j = -1;

	while(dest[i])
		i++;
	while(src[++j])
		dest[i++] = src[j];
	dest[i] = '\0';
	return dest;
}