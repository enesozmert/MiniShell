#include "../../include/header.h"

int	commands_clear(t_command *commands)
{
	int	i;

	i = 0;
	while (commands[i].type != NULL)
	{
		// printf("type : %s | arg : %s\n", commands[i].type, commands[i].arg);
		// if (commands[i].arg != NULL)
			free(commands[i].arg);
		i++;
	}
	// free(commands);
	return (1);
}

