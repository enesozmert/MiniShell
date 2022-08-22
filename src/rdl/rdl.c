#include "../../include/header.h"

t_rdl *rdl_init(t_rdl *rdl)
{
	int i;
	char **split_str;

	i = 0;
	if (rdl == NULL)
		rdl = malloc(sizeof(t_rdl) * 1);
	rdl->main_str = ft_read_line();
	rdl->keyword_list = malloc(sizeof(t_keyword) * 8);
	rdl->operator_list = malloc(sizeof(t_operator) * 8);
	rdl->len = ft_strlen(rdl->main_str);
	split_str = ft_split(rdl->main_str, ' ');
	// rdl->token = token_add(rdl->token, ft_split(rdl->main_str ,' '));
	while (split_str[i])
		i++;
	rdl->word_count = i;
	return (rdl);
}

void rdl_clear(t_rdl *rdl)
{
	free(rdl->keyword_list);
	free(rdl->operator_list);
	free(rdl->main_str);
	free(rdl->token);
	// if (rdl != NULL)
	// 	free(rdl);
}
