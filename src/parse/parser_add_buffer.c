#include "../../include/header.h"

void parser_add_buffer(t_rdl *rdl, char *buffer, int *k)
{
	int i;

	i = *k;
	if (buffer != NULL && ft_strlen(buffer) > 0)
	{
		buffer[++i] = '\0';
		parser_add(rdl, buffer);
		i = -1;
	}
	*k = i;
}

void parser_add_keyword(t_rdl *rdl, char *buffer)
{
	t_token token;
	char	*keyword;

	token.context = ft_strdup(buffer);
	token.t_flag = 0;
	keyword = keyword_trim(rdl->buffer);
	if (is_keyword(rdl->keyword_list, keyword))
	{
		rdl->token = token_add(rdl->token, token);
		ft_bzero(buffer, ft_strlen(buffer));
	}
	free(keyword);
	free(token.context);
}

void parser_add(t_rdl *rdl, char *buffer)
{
	t_token token;

	token.t_flag = -1;
	token.context = ft_strdup(buffer);
	rdl->token = token_add(rdl->token, token);
	ft_bzero(buffer, ft_strlen(buffer));
	free(token.context);
}