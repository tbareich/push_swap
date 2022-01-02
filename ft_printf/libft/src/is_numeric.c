char	is_numeric(char *str)
{
	if (str == 0)
		return 0;
	if (str[0] == '-')
		++str;
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		++str;
	}
	return (1);
}