#include "../../include/header.h"

char *env_path(char *env, char *cmd)
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
}

char **env_init(char **env)
{
	int		i;
	int		count;
	char	**new;

	i = -1;
	count = 0;
	while (env[count] != NULL)
		count++;
	if (!(new = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (env[++i] != NULL)
		new[i] = ft_strdup(env[i]);
	new[i] = NULL;
	return (new);
}

void set_env()
{

}