#include "../../include/header.h"

int env_asc(char **env)
{
	int i = 0;
	int j = 0;
	char *temp;

	while (env[i + 1])
	{
		if (env[i][j] < env[i + 1][j])
		{
			temp = ft_strdup(env[i]);
			env[i] = ft_strdup(env[i + 1]);
			env[i + 1] = ft_strdup(temp);
			i = 0;
		}
		else if (env[i][j] == env[i + 1][j])
		{
			j++;
		}
		else
			i++;
	}
	g_env.env = env;
	return (0);
}