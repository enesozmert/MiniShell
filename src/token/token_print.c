#include "../../include/header.h"

int print_token(t_token *token)
{
	int size;

	size = 0;
	printf("-------------------\n");
	while (token)
	{
		ft_putstr_fd((token)->context, 1);
		ft_putstr_fd("\n", 1); 
		token = token->next;
		size++;
	}
	printf("-------------------\n");
	return (size);
}
