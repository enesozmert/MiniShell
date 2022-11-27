#include "../../include/header.h"

void parser_add_char(t_rdl *rdl, char c)
{
	char str[2];
	t_token token;

	str[0] = c;
	str[1] = '\0';
	token.t_flag = -1;
	token.context = ft_strdup(str);
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
	char redir[2];
	t_token token;

	redir[0] = c;
	redir[1] = '\0';
	token.context = ft_strdup(redir);
	token.t_flag = 5;
	if (is_redir(rdl, redir[0]))
		rdl->token = token_add(rdl->token, token);
}

void parser_add_option(t_rdl *rdl, char c)
{
	char option[2];
	t_token token;

	option[0] = c;
	option[1] = '\0';
	token.context = ft_strdup(option);
	token.t_flag = 5;
	if (is_option(option[0]))
		rdl->token = token_add(rdl->token, token);
}

void parser_add_pipe(t_rdl *rdl, char c)
{
	char pipe[2];
	t_token token;

	pipe[0] = c;
	pipe[1] = '\0';
	token.context = ft_strdup(pipe);
	token.t_flag = 6;
	if (is_pipe(token.context[0]))
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