#include "../../include/header.h"

void parser_add_buffer(int *j, t_rdl *rdl)
{
	int i;

	i = *j; 
	rdl->buffer[i] = '\0';
	i = 0;
	parser_add(rdl, rdl->buffer, 0);
	*j = i;
}