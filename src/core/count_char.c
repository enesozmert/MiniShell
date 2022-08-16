#include "../../include/header.h"

int	count_char(char *str, char c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}