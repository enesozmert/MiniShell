#include "../../include/header.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	int i;
	int size;
	t_token *token;
	t_readline_prop rd_prop;

	token = NULL;
	i = 0;
	size = 0;
	while (1)
	{
		rd_prop = ft_read_line();
		token = lexical_add(ft_split(rd_prop.str, ' '));
		my_add_history(rd_prop.str);
		if (strncmp(rd_prop.str, "!lx", 3) == 0)
			size = print_lexical(token);
		i++;
		free(rd_prop.str);
	}
	return 0;
}
