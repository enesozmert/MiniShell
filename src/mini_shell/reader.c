#include "../../include/header.h"

t_rdl_prop ft_read_line(void)
{
	static	int		id = 0;
	t_rdl_prop		rd_prop;
	t_word			*word;
	int				i;
	char			**str;

	i = 0;
	rd_prop.main_str = readline("->");
	rd_prop.len = ft_strlen(rd_prop.main_str);
	str = ft_split(rd_prop.main_str, ' ');
	while (str[i])
		i++;
	rd_prop.word_count = i;
	word = malloc(sizeof(t_word) * i + 1);
	i = 0;
	while (str[i])
	{
		rd_prop.word[i].id = id;
		rd_prop.word[i].str = str[i];
		rd_prop.word[i].len = ft_strlen(str[i]);
		i++;
	}
	return (rd_prop);
}