#include "../../include/header.h"

int keyword_trim_len(char *str)
{
    int i;
	int j;	
	int flag;

	i = 0;
	j = 0;
    flag = 0;
	while(str[i])
	{
	    flag = 0;
		if(str[i] == '\'')
		{
			i++;
			while(str[i] != '\'')
			{
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
		    j++;
		    i++;
		}
		if(flag == 0)
		    i++;
	}
	return (j);
}