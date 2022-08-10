#include "../../include/header.h"

t_readline_prop ft_read_line(void)
{
	t_readline_prop rd_prop;
	t_word			*word;
	int				i;
	char			**str;

	i = 0;
	word = malloc(sizeof(t_word));
	rd_prop.word = word;
	rd_prop.word->str = readline("->");
	rd_prop.len = ft_strlen(rd_prop.word->str);
	str = ft_split(rd_prop.word->str, ' ');
	while (str[i])
		i++;
	rd_prop.word_count = i;
	free(str);
	return (rd_prop);
}