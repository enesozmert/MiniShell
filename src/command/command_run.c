#include "../../include/header.h"

int command_run(t_rdl *rdl)
{
    int		i;
	int		handle_code;
	
	i = 0;
	handle_code = 0;
	while (rdl->command_list[i].keyword != NULL)
	{
		if (rdl->command_list[i].count > 0)
			handle_code = rdl->command_list[i].f(&rdl->command_list[i]);
		env_add("?", ft_itoa(handle_code));
        if (handle_code == -1)
            return (-1);
		i++;
	}
	command_clear(rdl);
	return (0);
}