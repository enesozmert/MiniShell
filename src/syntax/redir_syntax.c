#include "../../include/header.h"

int redir_syntax(t_rdl *rdl)
{
    if (rdl->token->id == 0)
        return (0);
    if (rdl->token->len == 1)
    {
        if (rdl->token->context[0] == '>')
            rdl->redir_prop->output_count++;
        else if (rdl->token->context[0] == '<')
            rdl->redir_prop->input_count++;
        if ((rdl->token->context[0] == '>' && rdl->token->next->context[0] == '<')
            || (rdl->token->context[0] == '<' && rdl->token->next->context[0] == '>'))
            return (103);
    }
    if (rdl->redir_prop->input_count > 2 || rdl->redir_prop->output_count > 2)
        return (103);
    if (rdl->token->next->context[0] != '>')
        rdl->redir_prop->output_count = 0;
    else if (rdl->token->next->context[0] != '<')
        rdl->redir_prop->input_count = 0;
    return (0);
}