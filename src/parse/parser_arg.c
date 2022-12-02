#include "../../include/header.h"

/* static int is_keyw(int *k, t_rdl *rdl)
{
	int i;
	int tmp_i;

    i = *k;
	tmp_i = *k;
	printf("is_keyw: %c\n", rdl->main_str[i]);
	parser_arg_keyword(&i, rdl);
	if (ft_strlen(rdl->buffer) > 0)
		rdl->buffer = keyword_trim(rdl->buffer);
	if (is_keyword(rdl, rdl->buffer) && ft_strlen(rdl->buffer) > 0)
	{
		i = *k;

		*k = i;
		printf("keyword: %s\n", rdl->buffer);
		return (1);
	}
	else
	{
		i = tmp_i;
		// i--;
		return 0;
	}
	i--;
	i = *k;

	*k = i;
	return (0);
} */

void parser_arg(t_rdl *rdl)
{
	int i;
	int	key_flag;

	i = 0;
	key_flag = 0;
	parser_arg_iskeyword(&i, rdl);
	while (i < rdl->len && rdl->main_str[i] != '\0')
	{
		if (key_flag == 1)
		{
			parser_arg_iskeyword(&i, rdl);
			i--;
			key_flag = 0;
		}
		else if (is_quote(rdl, rdl->main_str[i]))
			parser_arg_quote(&i, rdl);
		else if (rdl->main_str[i] > 32 && ft_isalnum(rdl->main_str[i]))
			parser_arg_isnot(&i, rdl);
		else if (is_dollar(rdl->main_str[i]))
			parser_add_dollar(rdl, rdl->main_str[i]);
		else if (is_operator(rdl, rdl->main_str[i]))
			parser_add_operator(rdl, rdl->main_str[i]);
		else if (is_redir(rdl, rdl->main_str[i]))
			parser_arg_redir(&i, rdl);
		else if (is_option(rdl->main_str[i]) && rdl->main_str[i - 1] > 32 && rdl->main_str[i + 1] > 32)
			parser_add_option(rdl, rdl->main_str[i]);
		else if (is_pipe(rdl->main_str[i]) && is_pipe(rdl->main_str[i + 1]) == 0)
		{
			parser_arg_pipe(&i, rdl);
			key_flag = 1;
		}
		else if (ft_isalnum(rdl->main_str[i]) == 0 && rdl->main_str[i] > 32)
			parser_add_char(rdl, rdl->main_str[i]);
		else if (rdl->main_str[i] <= 32)
			parser_arg_space(&i, rdl);
		i++;
	}
}