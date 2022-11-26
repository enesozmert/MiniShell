#include "../../include/header.h"

void char_pos(int *k, t_rdl *rdl)
{
    int i;

    i = *k;
	while (rdl->main_str[i] <= 32)
		i++;
	*k = i;
}