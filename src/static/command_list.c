#include "../../include/header.h"

void	command_list(t_command *commands)
{
	commands[0] = (t_command){"echo", ""};
	commands[1] = (t_command){"cd", ""};
	commands[2] = (t_command){"pwd", ""};
	commands[3] = (t_command){"export", ""};
	commands[4] = (t_command){"unset", ""};
	commands[5] = (t_command){"env", ""};
	commands[6] = (t_command){"exit", ""};
}