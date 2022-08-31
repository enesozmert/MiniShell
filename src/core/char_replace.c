#include "../../include/header.h"

char *char_replace(char *str, char find, char replace)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == find)
			str[i] = replace;
		i++;
	}
	return (str);
}