#include "../../include/header.h"

int export_syntax(t_rdl *rdl)
{
    t_token *token_zero;
    t_token *first_arg;
    t_token *second_arg;

    token_zero = get_token_id(rdl->token, 0);
    if (ft_strncmp(token_zero->context, "export",
        token_zero->len))
        return (0);
    first_arg = rdl->token->next;
    second_arg = rdl->token->next->next->next;
    if (ft_strncmp(token_zero->context, "export",
        ft_strlen("export")) == 0)
    {
        if (first_arg->context[first_arg->len - 1] == ' ' ||
            second_arg->context[second_arg->len - 1] == ' ')
        {
            rdl->error_arg = ft_strdup("blabla");
            return (104);
        }
    }
    return (0);
}