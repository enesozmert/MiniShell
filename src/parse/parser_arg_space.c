#include "../../include/header.h"

void parser_arg_space(int *k, t_rdl *rdl)
{
	int i;
    
	i = *k; 
	while(rdl->main_str[i] <= 32)
		i++;
	parser_add(rdl, ft_strdup(" "));
	i--;
	*k = i;
}