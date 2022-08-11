#include "../../include/header.h"

void	command_list(t_command *commands)
{
	commands[0] = (t_command){"echo", NULL};
	commands[1] = (t_command){"cd", NULL};
	commands[2] = (t_command){"pwd", NULL};
	commands[3] = (t_command){"export", NULL};
	commands[4] = (t_command){"unset", NULL};
	commands[5] = (t_command){"env", NULL};
	commands[6] = (t_command){"exit", NULL};
	commands[7] = (t_command){NULL, NULL};
}