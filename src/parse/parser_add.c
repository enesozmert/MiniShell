#include "../../include/header.h"

void parser_add_space(t_rdl *rdl, char *buffer)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    token->t_flag = 8;
    token->context = ft_strdup(buffer);
    if (buffer[0] == 32)
        rdl->token = token_add(rdl->token, token);
    token_delone(token);
}

void parser_add_char(t_rdl *rdl, char c)
{
	char str[2];
	t_token *token;

	str[0] = c;
	str[1] = '\0';
	token = malloc(sizeof(t_token));
	token->t_flag = -1;
	token->context = ft_strdup(str);
	rdl->token = token_add(rdl->token, token);
	token_delone(token);
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
		rdl->token = token_add(rdl->token, token);
	}
	else if (c == '\"')
	{
		token->t_flag = 2;
		rdl->token = token_add(rdl->token, token);
	}
	token_delone(token);
}
