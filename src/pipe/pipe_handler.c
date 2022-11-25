#include "../../include/header.h"

int pipe_handler(t_rdl *rdl)
{
    printf("ok\n");
    int i;
    int len;
    int pipe_count;

    i = -1;
    len = token_size(rdl->token);
    pipe_count = 0;
    while (++i < len)
    {
        if (ft_strncmp(rdl->token->context, "|", rdl->token->len) == 0)
            pipe_count++;
        get_next_token(&rdl->token);
    }
    if (pipe_count < 1)
        return (0);
    rdl->pipe_str = ft_split(rdl->main_str, '|');
    return (1);
}
