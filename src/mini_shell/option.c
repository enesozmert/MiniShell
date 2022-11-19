#include "../../include/header.h"

int option_count(t_token *token)
{
    int		i;
    int		count;
    t_token	*tmp;

	i = -1;
    tmp = token;
    count = 0;
	while (++i < token_size(tmp))
	{
		if (tmp->context[0] == '-')
            count++;
		get_next_token(&tmp);
	}
    return (count);
}