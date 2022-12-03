#include "../../include/header.h"

int command_find(t_rdl *rdl, int token_id)
{
    int i;
    t_token *token;

    i = -1;
    token = get_token_id(rdl->token, token_id);
    if (rdl->pipe_prop->count > 0)
    {
        rdl->command_list[8].keyword = ft_strdup(token->context);
        return (8);
    }
    else if (rdl->redir_prop->count > 0)
    {
        rdl->command_list[9].keyword = ft_strdup(token->context);
        return (9);
    }
    else if (is_keyword_exec(rdl, token->context) && rdl->pipe_prop->count == 0 && rdl->redir_prop->count == 0)
    {
        rdl->command_list[7].keyword = ft_strdup(token->context);
        return (7);
    }
    while (rdl->command_list[++i].keyword != NULL)
    {
        if (ft_strncmp(rdl->command_list[i].keyword, token->context, ft_strlen(token->context)) == 0)
            return (i);
    }
    return (0);
}