#include "../../include/header.h"

int redir_handler(t_rdl *rdl)
{
    printf("ok\n");
    int i;
    int len;

    i = -1;
    len = token_size(rdl->token);
    while (++i < len)
    {
        if (rdl->token->context[0] != '>' && rdl->token->next->context[0] == '>')
            redir_output(rdl);
        else if (rdl->token->context[0] != '>' && rdl->token->next->context[0] == '>' && rdl->token->next->next->context[0] == '>')
            redir_output(rdl);
        else if (rdl->token->context[0] != '<' && rdl->token->next->context[0] == '<')
            redir_input(rdl);
        else if (rdl->token->context[0] != '<' && rdl->token->next->context[0] == '<' && rdl->token->next->next->context[0] == '<')
            redir_input(rdl);
        get_next_token(&rdl->token);
    }
    return (1);
}

int redir_output(t_rdl *rdl)
{
    if (rdl->token->type_id == 0)
        return (-1);
    rdl->redir_prop->file_name = ft_strjoin(rdl->redir_prop->file_name, rdl->token->context);
    printf("file name : %s\n", rdl->redir_prop->file_name);
    return (1);
}

int redir_input(t_rdl *rdl)
{
    (void)rdl;
    return (1);
}
