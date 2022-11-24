#include "../../include/header.h"

void parser_arg_keyword(t_rdl *rdl)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (rdl->main_str[i] <= 32)
		i++;
	while (rdl->main_str[i] != '\0' && rdl->main_str[i] > 32)
	{
		rdl->buffer[j++] = rdl->main_str[i];
		i++;
	}
	if (ft_strlen(rdl->buffer) > 0)
		rdl->buffer[j] = '\0';
}
