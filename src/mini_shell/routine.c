#include "../../include/header.h"

void	routine()
{
	printf("test\n");
	int				size;
	t_token			*token;
	t_readline_prop	rd_prop;

	token = NULL;
	size = 0;
	while (1)
	{
		rd_prop = ft_read_line();
		token = lexical_add(ft_split(rd_prop.word->str, ' '));
		my_add_history(rd_prop.word->str);
		if (strncmp(rd_prop.word->str, "!lx", 3) == 0)
			size = print_lexical(token);
		// free(rd_prop.main_str);
	}
}
