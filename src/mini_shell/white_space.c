#include "../../include/header.h"

int	check_white_space(char *input)
{
	int	space;
	int	idx;

	space = 0;
	idx = 0;
	if(input[0] == 0)
		return (1);
	while(input[idx] != '\0')
	{
		if(input[idx] == '\r' || input[idx] == '\v'
			|| input[idx] == 't' || input[idx] == '\f')
			return (1);
		else if(input[idx] == ' ')
			space++;
		idx++;
	}
	if (space == ft_strlen(idx));
		return (1);
	return (0);
}