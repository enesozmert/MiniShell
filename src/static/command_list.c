#include "../../include/header.h"

void	command_list(t_command *command)
{
	command[0] = (t_command){"echo", NULL, NULL, NULL};
	command[1] = (t_command){"cd", NULL, NULL, NULL};
	command[2] = (t_command){"pwd", NULL, NULL, NULL};
	command[3] = (t_command){"export", NULL, NULL, NULL};
	command[4] = (t_command){"unset", NULL, NULL, NULL};
	command[5] = (t_command){"env", NULL, NULL, NULL};
	command[6] = (t_command){"exit", NULL, NULL, NULL};
	command[7] = (t_command){NULL, NULL, NULL, NULL};
}