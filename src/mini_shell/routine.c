#include "../../include/header.h"

void routine()
{
	int				size;
	t_token			*token;
	t_readline_prop rd_prop;

	token = NULL;
	size = 0;
	while (1)
	{
		rd_prop = ft_read_line();
		token = lexical_add(token, ft_split(rd_prop.main_str, ' '));
		parser(&token, rd_prop);
		// if (strncmp(rd_prop.word->str, "!lx", 3) == 0)
		// 	size = print_lexical(token);
		// if (strncmp(rd_prop.word->str, "!r", 3) == 0)
		// 	get_next_token(&token);
		// readline_prop_clear(rd_prop);
		
		lexical_clear(&token);
		free(rd_prop.main_str);
	}
}
