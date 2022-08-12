#include "../../include/header.h"

int commands_size(t_command *commands)
{
	int i;

	i = 0;
	while (commands[i].type != NULL)
		i++;
	return (i);
}
