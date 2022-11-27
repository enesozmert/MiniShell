#include "../../include/header.h"

int pipe_handler(t_rdl *rdl)
{
    printf("ok\n");
    int i;
    int len;
    int count;

    i = -1;
    len = token_size(rdl->token);
    count = pipe_count(rdl);
    if (count < 1)
        return (-1);
    my_add_history(rdl->main_str);
    rdl->pipe_str = ft_split(rdl->main_str, '|');
    token_clear(&rdl->token);
    while (rdl->pipe_str[++i])
    {
        rdl->main_str = ft_strdup(rdl->pipe_str[i]);
        rdl->len = ft_strlen(rdl->pipe_str[i]);
        parser(rdl);
        command(rdl);
        free(rdl->main_str);
        rdl->len = 0;
        token_clear(&rdl->token);
        // printf("*****************\n");
    }
    return (1);
}