#include "../../include/header.h"

void routine()
{
	int size;
	t_rdl *rdl;
	char *str;

	size = 0;
	while (1)
	{
		str = ft_read_line();
		rdl = rdl_init(str);
		rdl->token = token_add(rdl->token, ft_split(rdl->main_str, ' '));
		parser(rdl);
		printf("comamnd type %s\n", rdl->command.type);
		printf("comamnd arg %s\n",  rdl->command.arg);
		my_add_history(rdl->main_str);
		commands_clear(rdl->command_list);
		rdl_clear(rdl);
		token_clear(&rdl->token);
	}
}
