#include "../../include/header.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	int i;
	int size;
	t_token *token;
	char *str;

	token = NULL;
	str = NULL;
	i = 0;
	size = 0;
	while (1)
	{
		str = readline("->");
		token = lexical_add(ft_split(str, ' '));
		add_history(str);
		if (strncmp(str, "!lx", 3) == 0)
			size = print_lexical(token);
		i++;
	}
	return 0;
}
