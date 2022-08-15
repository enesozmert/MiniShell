#include "../../include/header.h"

void routine()
{
	int size;
	t_rdl *rdl;

	size = 0;
	rdl = NULL;
	while (1)
	{
		rdl = rdl_init(rdl);
		if (!check_white_space(rdl->main_str))
		{
			parser(rdl);
			my_add_history(rdl->main_str);
			commands_clear(rdl->command_list);
			token_clear(&rdl->token);
			rdl_clear(rdl);
		}
	}
}
