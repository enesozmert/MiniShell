#include "../../include/header.h"

int	keywords_clear(t_keyword *keywords)
{
	int	i;

	i = 0;
	while (keywords[i].type != NULL)
	{
		// printf("type : %s | arg : %s\n", commands[i].type, commands[i].arg);
		// if (commands[i].arg != NULL)
			free(keywords[i].arg);
		i++;
	}
	// free(commands);
	return (1);
}

