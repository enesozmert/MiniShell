#include "../../include/header.h"

void routine()
{
	int size;
	t_rdl *rdl;

	size = 0;
	rdl = malloc(sizeof(t_rdl) * 1);
	while (1)
	{
		rdl->main_str = ft_read_line();
		if (!check_white_space(rdl->main_str))
		{
			rdl = rdl_init(rdl);
			parser(rdl);
			my_add_history(rdl->main_str);
			commands_clear(rdl->command_list);
			token_clear(&rdl->token);
			rdl_clear(rdl);
		}
	}
}
