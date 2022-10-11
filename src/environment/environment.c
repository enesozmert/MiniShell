#include "../../include/header.h"

/* char *env_path(char *env, char *cmd)
{
	int		idx;
	int		counter;
	char	*path;
	char	*path_cmd;
	int		path_cmd_idx;
		
	path_cmd_idx = 0;
	idx = 0;

	while(path[idx])
	{
		if(ft_strnstr(path[idx], cmd, ft_strlen(path[idx])))
			path_cmd_idx++;
		idx++;
	}
} */

char	*env_find_value(char *key)
{
	int	i;
	int	key_len;

	key_len = ft_strlen(key);
	i = -1;
	while(g_env.env[++i])
	{
		if (!ft_strncmp(g_env.env[i], key, key_len))
			return (g_env.env[i] + key_len + 1);
	}
	return ("");
}

char	*env_find_path(char *cmd)
{
	int			i;
	char		*temp;
	char		*new_path;
	char		**paths;
	struct stat s;

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

int	env_len(char **env)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (env[++i])
		count++;
	return (count);

}

void env_init(char **env)
{
	int		i;
	int		count;

	i = -1;
	count = env_len(env);
	g_env.env = (char **)malloc(sizeof(char *) * (count )+1);
	if (!g_env.env)
		return ;
	while (env[++i]){
		g_env.env[i] = ft_strdup(env[i]);
	if (g_env.env[i] == NULL)
			return ;
	}
}

/* void set_env(char )
{

} */