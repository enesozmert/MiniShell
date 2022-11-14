#include "../../include/header.h"

int env_add(char *key, char *value)
{
	int		i;
	int		count;
    char	**new_env;

	i = -1;
	count = env_len(g_env); 
    if (env_exist(key) == 0)
    {
		new_env = (char **)malloc(sizeof(char *) * (count) + 2);
		while (g_env[++i])
			new_env[i] = g_env[i];
		new_env[i] = ft_strjoin(key, "=");
		new_env[i] = ft_strjoin(new_env[i], value);
		new_env[i + 1] = NULL;
		g_env = new_env;
    }
    else
		env_update(key, value);
    return (0);
}