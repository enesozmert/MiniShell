#include "../../include/header.h"

int pwd_start(t_command command)
{
    (void)command;
    char	*cwd;

	cwd = getcwd(0, __SHRT_MAX__);
	printf("%s\n", cwd);
	if (!cwd)
		free(cwd);
	return 0;
}