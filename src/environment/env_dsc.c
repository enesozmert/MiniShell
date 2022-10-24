#include "../../include/header.h"

int env_dsc(char **env)
{
	int i;
	char *temp;

	i = 0;
	temp = NULL;
	while (env[i + 1])
	{
		if (ft_tolower(env[i][0]) < ft_tolower(env[i + 1][0]))
		{
			temp = ft_strdup(env[i]);
			env[i] = ft_strdup(env[i + 1]);
			env[i + 1] = ft_strdup(temp);
			i = 0;
		}
		else
			i++;
	}
	g_env.env = env;
	return (0);
}