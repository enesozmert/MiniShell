#include "../../include/header.h"

int syntax(t_rdl *rdl)
{
	int i;

	i = -1;
	while (++i < token_size(rdl->token))
	{
		if (exception_handler(rdl) == -1)
			return (-1);
		get_next_token(&rdl->token);
	}
	return (0);
}

// int syntax_analizer(t_rdl *rdl)
// {
// 	exception_handler(rdl)
// 	return (1);
// }
