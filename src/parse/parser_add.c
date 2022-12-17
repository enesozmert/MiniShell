#include "../../include/header.h"

/* token.t_flag = -1 ---> parser_add ||| parser_add_char
token.t_flag =  0 ---> parser_add_keyword
token.t_flag =	1 ---> parser_add_quote '\''
token.t_flag =	2 ---> parser_add_quote '\"'
token.t_flag =	3 ---> parser_add_dollar
token.t_flag =	4 ---> parser_add_operator
token.t_flag =	5 ---> parser_add_redir
token.t_flag =	6 ---> parser_add_pipe
token.t_flag =	7 ---> parser_add_option */

void parser_add_char(t_rdl *rdl, char c)
{
	char str[2];
	t_token token;

	str[0] = c;
	str[1] = '\0';
	token.t_flag = -1;
	token.context = ft_strdup(str);
	rdl->token = token_add(rdl->token, token);
	free(token.context);
}

void parser_add_quote(t_rdl *rdl, char c)
{
	t_quote quote;
	t_token *token;

	token = malloc(sizeof(t_token));
	quote = find_quote(rdl->quote_list, c);
	token->context = ft_strdup(quote.sybl);
	if (c == '\'')
	{
		token->t_flag = 1;
		rdl->token = token_add(rdl->token, *token);
	}
	else if (c == '\"')
	{
		token->t_flag = 2;
		rdl->token = token_add(rdl->token, *token);
	}
	token_delone(token);
}
