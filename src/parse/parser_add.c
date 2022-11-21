#include "../../include/header.h"

void	parser_add_operator(t_rdl *rdl, char c)
{
    t_operator operator;

    operator = find_operator(rdl, c);
    rdl->token = token_add(rdl->token, ft_strdup(operator.sybl), 1);
}

void	parser_add_notoperator(t_rdl *rdl, char c)
{
    t_operator	operator;
    t_token		*token_zero;
	int is_keyword_in_operator;
	int	is_operator;

	token_zero = get_token_id(rdl->token, 0);
	is_keyword_in_operator = keyword_in_operator(rdl, token_zero->context, c);
	if (is_keyword_in_operator == 1)
		is_operator = 1;
	else
		is_operator = 0;
    operator = find_operator(rdl, c);
    rdl->token = token_add(rdl->token, ft_strdup(operator.sybl), is_operator);
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