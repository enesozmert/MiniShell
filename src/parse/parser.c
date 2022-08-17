#include "../../include/header.h"

void parser(t_rdl *rdl)
{
	int i;
	int right;
	int left;

	i = -1;
	right = 0;
	left = 0;
	while (rdl->main_str[++i])
	{
		if (is_operator(rdl ,rdl->main_str[i]) == 1)
		{
			printf("is operator : %c\n", rdl->main_str[i]);
			left++;
		}
		else
		{
			char *str = ft_substr(rdl->main_str, right, left - 1);
			if (is_keyword(rdl, str) == 1)
				printf("is keyword : %s\n", str);
			right++;
		}
	}
	
}

t_rdl *parser_analizer(t_rdl *rdl)
{
	(void)rdl;
	return (NULL);
}
