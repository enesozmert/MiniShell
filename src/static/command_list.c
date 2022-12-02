#include "../../include/header.h"

void	command_list(t_command *command)
{
	command[0] = (t_command){"builtin", "echo", "3,5,6,7,10,12", NULL, echo_start, 0, 0, 0};
	command[1] = (t_command){"builtin", "cd", "5,6,10,13", NULL, cd_start, 0, 0, 0};
	command[2] = (t_command){"builtin", "pwd", "", NULL, pwd_start, 0, 0, 0};
	command[3] = (t_command){"builtin", "export", "5,6,8,10,11,12", NULL, export_start, 0, 0, 0};
	command[4] = (t_command){"builtin", "unset", "5,6,10", NULL, unset_start, 0, 0, 0};
	command[5] = (t_command){"builtin", "env", "", NULL, env_start, 0, 0, 0};
	command[6] = (t_command){"builtin", "exit", "", NULL, exit_start, 0, 0, 0};
	command[7] = (t_command){"exec", "none", "5,6,7,12,13", NULL, command_exec, 0, 0, 0};
	command[8] = (t_command){"exec", "none", "5,6,7,12,13", NULL, pipe_exec, 0, 0, 0};
	command[9] = (t_command){NULL, NULL, NULL, NULL, NULL, 0, 0, 0};
}