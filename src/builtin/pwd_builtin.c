#include "../../include/header.h"

int pwd_start(t_command command)
{
    (void)command;
    char	cwd[100];

	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s\n", cwd);
	// usleep(1000);
	return 0;
}