#include "../../include/header.h"

void parser_arg_is_quote(int c, int *k, t_rdl *rdl)
{
	int i;
	int j;

	i = *k;
	j = 0;
	i++;
	while (rdl->main_str[i] != c && rdl->main_str[i] != '\0')
		rdl->buffer[j++] = rdl->main_str[i++];
	rdl->buffer[j] = '\0';
	parser_arg_is(rdl);
	*k = i;
}
