#include "../../include/header.h"

void	command_list(t_command *command)
{
	command[0] = (t_command){"builtin", "echo", "3,5,6,9,11", NULL, echo_start, 0, NULL};
	command[1] = (t_command){"builtin", "cd", "5,6,9,12", NULL, cd_start, 0, NULL};
	command[2] = (t_command){"builtin", "pwd", "", NULL, pwd_start, 0, NULL};
	command[3] = (t_command){"builtin", "export", "5,6,7,9,10", NULL, export_start, 0, NULL};
	command[4] = (t_command){"builtin", "unset", "5,6,9", NULL, unset_start, 0, NULL};
	command[5] = (t_command){"builtin", "env", "", NULL, env_start, 0, NULL};
	command[6] = (t_command){"builtin", "exit", "", NULL, exit_start, 0, NULL};
	command[7] = (t_command){"exec", "none", "5,6,11,12", NULL, command_execv, 0, NULL};
	command[8] = (t_command){NULL, NULL, NULL, NULL, NULL, 0, NULL};
}