#include "../../include/header.h"

void	token_pre(t_rdl *rdl)
{
	int i;

	i = -1;
	while (++i < token_size(rdl->token))
	{
		if (rdl->token->type_id == 5 || rdl->token->type_id == 6)
        {
			rdl->token_type_pre_id = rdl->token->type_id;
            break ;
        }
		get_next_token(&rdl->token);
	}
}