#include "../../include/header.h"

char *keyword_trim(char *str)
{
  	int i;
	int j;
	int len;
	int flag = 0;
	char *dest;

	i = 0;
	j = 0;
	len = keyword_trim_len(str);
	dest = malloc(sizeof(char ) * len);
	while(str[i])
	{
	    flag = 0;
		if(str[i] == '\'')
		{
			i++;
			while(str[i] != '\'')
			{
				dest[j] = str[i];
				i++;
				j++;
			}
			if(str[i] == '\''){
			    flag = 1;
			    i++;
			}
		}
		else if(str[i] == '\"')
		{
			i++;
			while(str[i] != '\"')
			{
				dest[j] = str[i];
				i++;
				j++;
			}
			if(str[i] == '\"')
			{
			    flag = 1;
			    i++;
			}
		}
		else
		{
		    flag = 1;
		    dest[j++] = str[i++];
		}
		if(flag == 0)
		    i++;
	}
	dest[j] = '\0';
	return (dest);
}
