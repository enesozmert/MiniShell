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

/* void set_env()
{

} */