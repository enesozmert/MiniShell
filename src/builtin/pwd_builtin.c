#include "../../include/header.h"

int pwd_start(t_command *command)
{
	(void)command;
    char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (108);
	// printf("%s\n", cwd);
	ft_putstr_fd(cwd, command->file_fd);
	ft_putstr_fd("\n", command->file_fd);
	free(cwd);
	return (0);
}