#include "../../include/header.h"

void parser_add_char(t_rdl *rdl, char c)
{
	char str[2];
	t_token token;

	str[0] = c;
	str[1] = '\0';
	token.context = ft_strdup(str);
	token.t_flag = -1;
	rdl->token = token_add(rdl->token, token);
}

void parser_add_dollar(t_rdl *rdl, char c)
{
	t_token token;
	char dollar[2];

	dollar[0] = '$';
	dollar[1] = '\0';
	token.context = ft_strdup(dollar);
	token.t_flag = 3;
	if (is_dollar(c))
		rdl->token = token_add(rdl->token, token);
}

void parser_add_operator(t_rdl *rdl, char c)
{
	t_token token;
	t_operator operator;

	operator= find_operator(rdl, c);
	token.context = ft_strdup(operator.sybl);
	token.t_flag = 4;
	rdl->token = token_add(rdl->token, token);
}

void parser_add_redir(t_rdl *rdl, char c)
{
	t_token token;
	char dollar[2];

	dollar[0] = c;
	dollar[1] = '\0';
	token.context = ft_strdup(dollar);
	token.t_flag = 5;
	if (is_redir(rdl, c))
		rdl->token = token_add(rdl->token, token);
}

void parser_add_quote(t_rdl *rdl, char c)
{
	t_quote quote;
	t_token token;

	quote = find_quote(rdl, c);
	token.context = ft_strdup(quote.sybl);
	if (c == '\'')
	{
		token.t_flag = 1;
		rdl->token = token_add(rdl->token, token);
	}
	else if (c == '\"')
	{
		token.t_flag = 2;
		rdl->token = token_add(rdl->token, token);
	}
}

void parser_add_keyword(t_rdl *rdl, char *buffer)
{
	t_token token;

	token.context = ft_strdup(buffer);
	token.t_flag = 0;
	if (is_keyword(rdl, buffer))
	{
		rdl->token = token_add(rdl->token, token);
		ft_bzero(buffer, ft_strlen(buffer));
	}
}

void parser_add(t_rdl *rdl, char *buffer)
{
	t_token token;

	token.t_flag = -1;
	token.context = ft_strdup(buffer);
	rdl->token = token_add(rdl->token, token);
	ft_bzero(buffer, ft_strlen(buffer));
}