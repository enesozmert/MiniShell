#include "../../include/header.h"

t_readline_prop ft_read_line(void)
{
	t_readline_prop rd_prop;
	int i;
	char **str;

	i = 0;
	rd_prop.str = readline("->");
	rd_prop.len = ft_strlen(rd_prop.str);
	str = ft_split(rd_prop.str, ' ');
	while (str[i])
		i++;
	rd_prop.word_count = i;
	free(str);
	return (rd_prop);
}