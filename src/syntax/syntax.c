#include "../../include/header.h"

void syntax(t_rdl *rdl)
{
	int i;

	i = -1;
	while (++i < token_size(rdl->token))
	{
		if (exception_handler(rdl) == -1)
			break ;
		get_next_token(&rdl->token);
	}
}

// int syntax_analizer(t_rdl *rdl)
// {
// 	exception_handler(rdl)
// 	return (1);
// }
