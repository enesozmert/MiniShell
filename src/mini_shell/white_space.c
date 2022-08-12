#include "../../include/header.h"

int	check_white_space(char *input)
{
	int	space;
	int	i;

	space = 0;
	i = 0;
	if (input[0] == 0)
		return (1);
	while (input[i])
	{
		if (input[i] == '\r' || input[i] == '\v' || input[i] == '\t'
			|| input[i] == '\f')
			return (1);
		else if (input[i] == ' ')
			space++;
		i++;
	}
	if (space == (int)ft_strlen(input))
		return (1);
	return (0);
}