#include "../../include/header.h"

int command_run(t_command *command_list)
{
	printf("enesç\n");
    int		i;
	int		handle_code;
	
	i = 0;
	handle_code = 0;
	while (command_list[i].keyword != NULL)
	{
		if (command_list[i].count > 0)
			handle_code = command_list[i].f(&command_list[i]);
		env_add("?", ft_itoa(handle_code));
        if (handle_code == -1)
            return (-1);
		i++;
	}
	command_clear(command_list);
	return (0);
}