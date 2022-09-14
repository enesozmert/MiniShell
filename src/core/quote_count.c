#include "../../include/header.h"

int quote_count_left(char *str)
{
	int count;
	int i;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if ((str[i] == '\"' || str[i] == '\''))
		{
			count++;
			if ( str[i + 1] != '\"' && str[i + 1] != '\'')
				break ;
		}
		
	}
	return (count);
}

int quote_count_right(char *str)
{
	int count;
	int i;

	i = ft_strlen(str);
	count = 0;
	while (str[--i])
	{
		if ((str[i] == '\"' || str[i] == '\''))
		{
			count++;
			if (str[i - 1] != '\"' && str[i - 1] != '\'')
				break ;
		}
	}
	return (count);
}

int quote_count(char *str, int c)
{
	int count;
	int i;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == (char)c)
			count++;
	}
	return (count);
}