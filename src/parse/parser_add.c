#include "../../include/header.h"

void parser_add_operator(t_rdl *rdl, char c)
{
    t_operator operator;

    operator = find_operator(rdl, c);
    rdl->token = token_add(rdl->token, operator.sybl);
}

void parser_add_keyword(t_rdl *rdl, char *buffer)
{
    if (is_keyword(rdl, buffer) == 1)
    {
        rdl->token = token_add(rdl->token, ft_strdup(buffer));
        ft_bzero(buffer, ft_strlen(buffer));
    }
}

void parser_add_indentifier(t_rdl *rdl, char *buffer)
{
    if (is_keyword(rdl, buffer) == 0)
    {
        rdl->token = token_add(rdl->token, ft_strdup(buffer));
        ft_bzero(buffer, ft_strlen(buffer));
    }
}

void parser_add(t_rdl *rdl, char *buffer)
{
    parser_add_keyword(rdl, buffer);
    parser_add_indentifier(rdl, buffer);
}