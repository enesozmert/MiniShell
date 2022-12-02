#include "../../include/header.h"

int pipe_count(t_rdl *rdl)
{
    int i;
    int len;

    i = -1;
    len = token_size(rdl->token);
    while (++i < len)
    {
        if (rdl->token->type_id == 6)
            rdl->pipe_prop->count++;
        get_next_token(&rdl->token);
    }
    return (rdl->pipe_prop->count);
}