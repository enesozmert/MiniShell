#include "../../include/header.h"

int token_add_type_handler(t_rdl *rdl)
{
    int i;
    int handle_code;

    i = 0;
    handle_code = 0;
    while (rdl->token_type_list[i].name != NULL)
	{
        handle_code = rdl->token_type_list[i].f(rdl);
        if (handle_code == 1)
        {
            rdl->token_type_prop->token->type = ft_strdup(rdl->token_type_list[i].name);
            break ;
        }
        handle_code = 0;
		i++;
	}
    return (0);
}