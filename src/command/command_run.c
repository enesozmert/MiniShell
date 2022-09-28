#include "../../include/header.h"

int command_run(t_rdl *rdl)
{
    int			i;
	int			handle_code;

	i = 0;
	handle_code = 0;
	while (rdl->command_list[i].type != NULL)
	{
		if (rdl->command_list[i].count >= 1)
		    handle_code = rdl->command_list[i].f(rdl ,rdl->command_list[i]);
        if (handle_code == -1)
            return (-1);
		i++;
	}
	return (0);
}