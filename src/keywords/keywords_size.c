#include "../../include/header.h"

int commands_size(t_keyword *keywords)
{
	int i;

	i = 0;
	while (keywords[i].type != NULL)
		i++;
	return (i);
}
