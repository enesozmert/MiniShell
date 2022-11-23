#include "../../include/header.h"

void	parser_add_operator(t_rdl *rdl, char c)
{
    t_operator operator;
    t_token    token;

    operator = find_operator(rdl, c);
	token.t_flag = 1;
	token.context = ft_strdup(operator.sybl);
	token.in_quote = rdl->quote_prop->flag;
    rdl->token = token_add(rdl->token, token);
}

void	parser_add_notoperator(t_rdl *rdl, char c)
{
    char	str[2];
	t_token	token;


	str[0] = c;
    str[1] = '\0';
	token.t_flag = 0;
	token.context = ft_strdup(str);
    rdl->token = token_add(rdl->token, token);
}

void	parser_add_single_quote(t_rdl *rdl, char c)
{
	t_quote		quote;
	t_token		token;

	quote = find_quote(rdl, c);
	token.context = ft_strdup(quote.sybl);
	printf("rdl->quote_prop->flag : %d\n", rdl->quote_prop->flag);
    if (c == '\'')
	{
		token.t_flag = 2;
	    rdl->token = token_add(rdl->token, token);
	}
}

void	parser_add_double_quote(t_rdl *rdl, char c)
{
	t_quote		quote;
	t_token		token;

	quote = find_quote(rdl, c);
	token.context = ft_strdup(quote.sybl);
	if (c == '\"')
	{
		token.t_flag = 3;
	    rdl->token = token_add(rdl->token, token);
	}
}

void	parser_add_dollar(t_rdl *rdl, char c)
{
	t_token    token;
    char dollar[2];

	dollar[0] = '$';
	dollar[1] = '\0';
	token.t_flag = 1;
	token.context = ft_strdup(dollar);
    if (is_dollar(c))
	    rdl->token = token_add(rdl->token, token);
}

void	parser_add(t_rdl *rdl, char *buffer)
{
	t_token    token;

	token.t_flag = 0;
	token.context = ft_strdup(buffer);
    if (is_keyword(rdl, buffer) == 1)
    {
        rdl->token = token_add(rdl->token, token);
        ft_bzero(buffer, ft_strlen(buffer));
    }
    else if (is_keyword(rdl, buffer) == 0)
    {
        rdl->token = token_add(rdl->token, token);
        ft_bzero(buffer, ft_strlen(buffer));
    }
}