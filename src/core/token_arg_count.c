#include "../../include/header.h"

int token_arg_count(t_token *token)
{
	int		i;
    int		count;
    t_token	*token_cpy;

	i = -1;
	count = 0;
	token_cpy = (t_token *)token;
	while (++i < token_size(token))
	{
		if (token_cpy->type && ft_strncmp(token_cpy->type, "arg", ft_strlen(token_cpy->type)) == 0)
			count++;
		token_cpy = token_cpy->next;
	}
	token_cpy = token;
	return (count);
}