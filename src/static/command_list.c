#include "../../include/header.h"

void	command_list(t_command *command)
{
	command[0] = (t_command){"builtin", "echo", "6,8", NULL, echo_start, 0};
	command[1] = (t_command){"builtin", "cd", "6,9", NULL, cd_start, 0};
	command[2] = (t_command){"builtin", "pwd", "", NULL, pwd_start, 0};
	command[3] = (t_command){"builtin", "export", "4,5,6,7", NULL, export_start, 0};
	command[4] = (t_command){"builtin", "unset", "6", NULL, unset_start, 0};
	command[5] = (t_command){"builtin", "env", "", NULL, env_start, 0};
	command[6] = (t_command){"builtin", "exit", "", NULL, exit_start, 0};
	command[7] = (t_command){"exec", "none", "9", NULL, command_execv, 0};
	command[8] = (t_command){NULL, NULL, NULL, NULL, NULL, 0};
}