#include "../../include/header.h"

int keyword_syntax(t_rdl *rdl, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_tolower(str[i]);
	if (keyword_quoute_syntax(str))
		return (0);
	str = keyword_trim(str);
    if (is_keyword(rdl, str))
        return (1);
    return (0);
}

int keyword_quoute_syntax(char *str)
{
	int i;
	int d_q;
	int s_q;

	i = 0;
	d_q = 0;
	s_q = 0;
	while(str[i++])
	{
		if(str[i] == '\"')
		{
			while(str[i] != '\"')
				i++;
			d_q++;
		}
		else if(str[i] == '\'')
		{
			while(str[i] != '\'')
				i++;
			s_q++;
		}
	}
	if(d_q % 2 != 0 || s_q % 2 != 0)
		return (1);
	else
		return (0);
}
