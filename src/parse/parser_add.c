#include "../../include/header.h"

void parser_add_operator(t_rdl *rdl, char c)
{
    t_operator operator;

    operator = find_operator(rdl, c);
    rdl->token = token_add(rdl->token, ft_strdup(operator.sybl), 1);
}

void parser_add(t_rdl *rdl, char *buffer, int flag)
{
    if (is_keyword(rdl, buffer) == 1)
    {
        rdl->token = token_add(rdl->token, ft_strdup(buffer), flag);
        ft_bzero(buffer, ft_strlen(buffer));
    }
    else if (is_keyword(rdl, buffer) == 0)
    {
        rdl->token = token_add(rdl->token, ft_strdup(buffer), flag);
        ft_bzero(buffer, ft_strlen(buffer));
    }
}