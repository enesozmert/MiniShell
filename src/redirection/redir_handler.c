#include "../../include/header.h"

int redir_output(t_rdl *rdl)
{
    printf("redir_output\n");
    (void)rdl;
    return (1);
}

int redir_input(t_rdl *rdl)
{
    printf("redir_output\n");
    (void)rdl;
    return (1);
}

static int redir_file_name(t_rdl *rdl)
{
    // printf("redir_file_name\n");
    rdl->redir_prop->file_name = ft_strdup(rdl->token->context);
    return (1);
}

static int redir_context(t_rdl *rdl)
{
    // printf("redir_context\n");
    if (rdl->token->type_id == 0)
        return (-1);
    rdl->redir_prop->context = ft_strdup(rdl->token->context);
    return (1);
}

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
            redir_context(rdl);
        // else if (rdl->token->context[0] != '>' && rdl->token->next->context[0] == '>' && rdl->token->next->next->context[0] == '>')
        //     redir_output(rdl);
        else if (rdl->token->context[0] != '>' && (rdl->token->next->context[0] != '>' || rdl->token->next->next->context[0] != '>'))
            redir_file_name(rdl);
        else if (rdl->token->context[0] != '<' && rdl->token->next->context[0] == '<')
            redir_context(rdl);
        // else if (rdl->token->context[0] != '<' && rdl->token->next->context[0] == '<' && rdl->token->next->next->context[0] == '<')
        //     redir_input(rdl);
        else if (rdl->token->context[0] == '<' && rdl->token->next->context[0] != '<' && rdl->token->next->next->context[0] != '<')
            redir_file_name(rdl);
        get_next_token(&rdl->token);
    }
    printf("context : %s\n", rdl->redir_prop->context);
    printf("file name : %s\n", rdl->redir_prop->file_name);
    return (1);
}
