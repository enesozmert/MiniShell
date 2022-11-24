#include "../../include/header.h"

void parser_add_buffer(t_rdl *rdl, char *buffer, int *k)
{
	int i;

	i = *k;
	if (buffer != NULL && ft_strlen(buffer) > 0)
	{
		parser_add(rdl, buffer);
		i = -1;
	}
	*k = i;
}