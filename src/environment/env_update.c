#include "../../include/header.h"

int env_update(char *key, char *value)
{
    int		key_id;
    char	*key_find;
    char	*result;

    key_id = env_find_id(key);
    key_find = ft_split(g_env[key_id], '=')[0];
    result = ft_strjoin(key_find, "=");
	result = ft_strjoin(result, value);
	g_env[key_id] = ft_strdup(result);
    return (0);
}
