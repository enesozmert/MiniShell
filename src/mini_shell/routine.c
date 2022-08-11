#include "../../include/header.h"

void routine()
{
	int				size;
	t_token			*token;
	t_rdl_prop		*rdl_prop;
	char			*str;
	t_command		command;

	token = NULL;
	size = 0;
	while (1)
	{
		str = ft_read_line();
		rdl_prop = rdl_prop_init(str);
		token = lexical_add(token, ft_split(rdl_prop->main_str, ' '));
		command = parser(&token, rdl_prop);
		my_add_history(rdl_prop->main_str);
		rdl_prop_clear(rdl_prop);
		lexical_clear(&token);
	}
}
