#include "../../include/header.h"

int count_matris(void **matris)
{
	int i;

	i = 0;
	while (matris[i])
		i++;
	return (i);
}
