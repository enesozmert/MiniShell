#include "../../include/header.h"


void rdl_prop_clear(t_rdl_prop rd_prop)
{
	int i;

	i = 0;
	while (i < rd_prop.word_count)
	{
		free(rd_prop.word[i].str);
		i++;
	}
	free(rd_prop.main_str);
}
