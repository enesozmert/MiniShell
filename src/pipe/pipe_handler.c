#include "../../include/header.h"

void pipe_handler(t_rdl *rdl)
{
    int i;
    int len;
    int count;
    int nproc;

    i = -1;
    nproc = rdl->pipe_prop->count + 1;
    len = token_size(rdl->token);
    count = rdl->pipe_prop->count;
    if (count < 1)
        return;
    my_add_history(rdl->main_str);
    rdl->pipe_str = ft_split(rdl->main_str, '|');
    token_clear(&rdl->token);
    while (++i < nproc)
    {
        rdl->main_str = ft_strdup(rdl->pipe_str[i]);
        rdl->len = ft_strlen(rdl->pipe_str[i]);
        parser(rdl);
        command(rdl);
        token_clear(&rdl->token);
        free(rdl->main_str);
        printf("*****************\n");
    }
    while (nproc-- > 0)
        waitpid(-1, 0, 0);
}