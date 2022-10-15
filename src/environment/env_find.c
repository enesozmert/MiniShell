#include "../../include/header.h"

char	*env_find_value(char *key)
{
	int	i;
	int	key_len;

	i = -1;
	key_len = ft_strlen(key);
	while(g_env.env[++i])
	{
		if (ft_strncmp(g_env.env[i], key, key_len) == 0)
			return (g_env.env[i] + key_len + 1);
	}
	return (NULL);
}

char	*env_find_path(char *cmd)
{
	int			i;
	char		*temp;
	char		*new_path;
	char		**paths;
	struct	stat	s;

	temp = env_find_value("PATH");
	paths = ft_split(temp, ':');
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin("/", cmd);
		new_path = ft_strjoin(paths[i], temp);
		free(temp);
		if (stat(new_path, &s) == 0)
			return (new_path);
		free(new_path);
	}
	return (ft_strdup(cmd));
}
