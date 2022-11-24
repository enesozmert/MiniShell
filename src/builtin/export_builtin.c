#include "../../include/header.h"

int export_start(t_command command)
{
    int		i;
    int		size;
    char	*key;
	char	*value;
	char	*tmp_value;
    char	*identifier;

    i = -1;
    key = ft_strdup("");
    value = ft_strdup("");
    tmp_value = ft_strdup("");
    identifier = ft_strdup("");
    size = token_size(command.tokens);
    if (size == 0)
    {
        while (g_env.env[++i])
        {
            printf("declare -x %s\n", g_env.env[i]);
        }
    }
    i = -1;
    while (++i < size)
    {
        if (command.tokens->type_id == 6)
            identifier = ft_strjoin(identifier, command.tokens->context);
		if (command.tokens->type_id == 8)
		{
            key = ft_strdup(command.tokens->context);
			tmp_value = env_find_value(key);
            if (tmp_value != NULL)
			    value = ft_strjoin(value, tmp_value);
		}
        if (command.tokens->type_id == 9)
        {
            value = ft_strjoin(value, command.tokens->context);
            if (ft_strncmp(value, " ", 1) == 0)
                return (206);
        }
        get_next_token(&command.tokens);
    }
	env_add(identifier, value);
    // env_asc(g_env.env);
    free(key);
    free(value);
    free(identifier);
    return (0);
}