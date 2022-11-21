#include "../../include/header.h"

char	*env_find_value(char *key)
{
	int	i;
	int	key_len;
	int key_id;

	i = -1;
	key_len = ft_strlen(key);
	key_id = env_find_id(key);
	if (key_id == -1)
		return (0);
	while(g_env.env[++i])
	{
		if (ft_strncmp(g_env.env[i], key, key_len) == 0)
			return (g_env.env[i] + key_len + 1);
	}
	return (0);
}

int	env_find_id(char *key)
{
	int		i;
	int		key_len;
	char	*key_find;

	i = -1;
	key_len = ft_strlen(key);
	while(g_env.env[++i])
	{
		key_find = ft_split(g_env.env[i], '=')[0];
		if (ft_strncmp(key_find, key, key_len) == 0)
			return (i);
	}
	return (-1);
}
