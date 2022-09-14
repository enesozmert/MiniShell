#include "../../include/header.h"

char *keyword_trim(char *str)
{
    int i;
	int j;
	int len;
	char *dest;

	i = -1;
	j = 0;
	len = ft_strlen(str) - quote_count(str, '\'') - quote_count(str, '\'') + 1;
	dest = malloc(sizeof(char ) * len);
	while (str[++i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			dest[j++] = str[i];
	}
	return (dest);
}