#include "../../include/header.h"

int command_run(t_rdl *rdl)
{
    int			i;
	int			handle_code;
	char		*path;

	i = 0;
	handle_code = 0;
	while (rdl->command_list[i].type != NULL)
	{
		if (rdl->command_list[i].count > 0)
		    handle_code = rdl->command_list[i].f(rdl->command_list[i]);
        if (handle_code == -1)
		{
			path = env_find_path(rdl->token[0].context);
			execve(path, &rdl->token[0].context, g_env.env);
            return (0);
		}
		else
			return (-1);
		i++;
	}
	command_clear(rdl);
	return (0);
}