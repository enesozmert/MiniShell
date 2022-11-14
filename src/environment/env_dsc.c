#include "../../include/header.h"

int env_dsc(char **env)
{
	int i;
	int j;
	char *temp;

	j = 0;
	i = 0;
	temp = NULL;
	while (env[i + 1])
	{
		if (ft_tolower(env[i][j]) < ft_tolower(env[i + 1][j]))
		{
			temp = ft_strdup(env[i]);
			env[i] = ft_strdup(env[i + 1]);
			env[i + 1] = ft_strdup(temp);
			i = 0;
		}
		else if (ft_tolower(env[i][j]) == ft_tolower(env[i + 1][j]))
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	g_env = env;
	return (0);
}