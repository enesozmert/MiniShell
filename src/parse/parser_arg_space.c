#include "../../include/header.h"

void parser_arg_space(int *k, t_rdl *rdl)
{
	int i;
    
	i = *k; 
	while(rdl->main_str[i] <= 32)
		i++;
	printf("who: %c\n", rdl->main_str[i]);
	if(is_pipe(rdl->main_str[i]) == 0 && is_redir(rdl, rdl->main_str[i]) == 0)
		parser_add(rdl, ft_strdup(" "));
	i--;
	*k = i;
}