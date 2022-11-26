#include "../../include/header.h"

int keyword_syntax(t_rdl *rdl)
{
	int		i;
	t_token	*token;

	i = -1;
	if (rdl->token->id != 0)
		return (0);
	token = get_token_type_id(rdl->token, 0);
	while (token->context[++i])
		token->context[i] = ft_tolower(token->context[i]);
	token->context = keyword_trim(token->context);
	if (is_keyword(rdl, token->context) == 1)
	{
		// rdl->error_arg = malloc(sizeof(char) * ft_strlen(token->context));
		// rdl->error_arg = NULL;
		return (0);
	}
	else
	{
		rdl->error_arg = ft_strdup(token->context);
		return (101);
	}
	return (0);
}