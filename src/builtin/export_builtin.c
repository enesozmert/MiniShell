#include "../../include/header.h"

int export_start(t_command command)
{
    int		i;
    int		size;
    char	*key;
	char	*value;
    char	*identifier;

    i = -1;
    key = ft_strdup("");
    value = ft_strdup("");
    identifier = ft_strdup("");
    size = token_size(command.tokens);
    while (++i < size)
    {
        if (command.tokens->type_id == 4)
            identifier = ft_strjoin(identifier, command.tokens->context);
		if (command.tokens->type_id == 6)
            key = ft_strjoin(key, command.tokens->context);
        if (command.tokens->type_id == 7)
            value = ft_strjoin(value, command.tokens->context);
        get_next_token(&command.tokens);
    }
	env_add(identifier, value);
    // env_asc(g_env.env);
    free(key);
    free(value);
    free(identifier);
    return (0);
}
