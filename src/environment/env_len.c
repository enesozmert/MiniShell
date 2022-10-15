#include "../../include/header.h"

int	env_len(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}