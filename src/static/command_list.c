#include "../../include/header.h"

void	command_list(t_command *command)
{
	command[0] = (t_command){"echo", ((char **)0), NULL, echo_start, 0};
	command[1] = (t_command){"cd", ((char **)0), NULL, NULL, 0};
	command[2] = (t_command){"pwd", ((char **)0), NULL, NULL, 0};
	command[3] = (t_command){"export", ((char **)0), NULL, NULL, 0};
	command[4] = (t_command){"unset", ((char **)0), NULL, NULL, 0};
	command[5] = (t_command){"env", ((char **)0), NULL, NULL, 0};
	command[6] = (t_command){"exit", ((char **)0), NULL, NULL, 0};
	command[7] = (t_command){NULL, ((char **)0), NULL, NULL, 0};
}