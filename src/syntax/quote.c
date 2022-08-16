#include "../../include/header.h"

int	single_quote(t_rdl *rdl)
{
	int		i;
	int		j;
	static	int	count = 0;
	t_token	*token_cpy;

	j = -1;
	i = -1;
	token_cpy = rdl->token;
	while (token_cpy)
	{
		count += count_char(token_cpy->context, '\'');
		printf("count %d\n", count);
		if (count % 2)
			return (0);
		token_cpy = token_cpy->next;
	}
	return (1);
}

int double_quote()
{
	return (1);
}