#include "../../include/header.h"

int command_in_token_type(t_rdl *rdl, int command_id, int token_id)
{
	int		i;
	t_token *token;
    char	**token_types_id;

	i = -1;
	token_types_id = ft_split(rdl->command_list[command_id].token_types_id, ',');
	token = get_token_id(rdl->token, token_id);
	while (token_types_id[++i] != NULL)
	{
		if (token->type_id == ft_atoi(token_types_id[i]))
			return (1);
	}
	return (0);
}