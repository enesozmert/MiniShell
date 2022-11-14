#include "../../include/header.h"

int env_delete(char *key)
{
	int		i;
    int     del_env_id;
	int		count;
    char	**new_env;

	i = -1;
	count = env_len(g_env); 
    del_env_id = env_find_id(key);
    if (env_exist(key) == 1)
    {
		new_env = (char **)malloc(sizeof(char *) * (count));
		while (g_env[++i])
        {
            if (del_env_id != i)
			    new_env[i] = g_env[i];
        }
		new_env[i + 1] = NULL;
		g_env = new_env;
    }
    return (0);
}
