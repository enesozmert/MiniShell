#include "../../include/header.h"

t_rdl *rdl_init(t_rdl *rdl)
{
	int i;
	char **split_str;

	i = 0;
	if (rdl == NULL)
		rdl = malloc(sizeof(t_rdl) * 1);
	rdl->main_str = ft_read_line();
	rdl->command_list = malloc(sizeof(t_command) * 8);
	rdl->syntax_list = malloc(sizeof(t_syntax) * 11);
	rdl->len = ft_strlen(rdl->main_str);
	split_str = ft_split(rdl->main_str, ' ');
	while (split_str[i])
		i++;
	rdl->word_count = i;
	rdl->token = token_add(rdl->token, ft_split(rdl->main_str, ' '));
	return (rdl);
}

void rdl_clear(t_rdl *rdl)
{
	free(rdl->command_list);
	free(rdl->main_str);
	free(rdl->token);
	free(rdl->syntax_list);
	// if (rdl != NULL)
	// 	free(rdl);
}
