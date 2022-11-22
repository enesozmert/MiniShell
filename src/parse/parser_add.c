#include "../../include/header.h"

void	parser_add_operator(t_rdl *rdl, char c)
{
    t_operator operator;

    operator = find_operator(rdl, c);
    rdl->token = token_add(rdl->token, ft_strdup(operator.sybl), 1);
}

void	parser_add_notoperator(t_rdl *rdl, char c)
{
    char str[2];

    str[0] = c;
    str[1] = '\0';
    rdl->token = token_add(rdl->token, ft_strdup(str), 0);
}

void	parser_add_quote(t_rdl *rdl, char c)
{
	t_quote quote;

	quote = find_quote(rdl, c);
    if (c == '\'')
	    rdl->token = token_add(rdl->token, ft_strdup(quote.sybl), 2);
    else if (c == '\"')
	    rdl->token = token_add(rdl->token, ft_strdup(quote.sybl), 3);
}

void	parser_add_dollar(t_rdl *rdl, char c)
{
    char *dollar = "$";
    if (is_dollar(c))
	    rdl->token = token_add(rdl->token, dollar, 4);
}

void	parser_add(t_rdl *rdl, char *buffer)
{
    if (is_keyword(rdl, buffer) == 1)
    {
        rdl->token = token_add(rdl->token, ft_strdup(buffer), rdl->t_flag);
        ft_bzero(buffer, ft_strlen(buffer));
    }
    else if (is_keyword(rdl, buffer) == 0)
    {
        rdl->token = token_add(rdl->token, ft_strdup(buffer), rdl->t_flag);
        ft_bzero(buffer, ft_strlen(buffer));
    }
}