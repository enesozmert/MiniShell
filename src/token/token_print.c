#include "../../include/header.h"

int print_token(t_token *token)
{
	int size;

	size = 0;
	printf("-------------------\n");
	while (token)
	{
		ft_putnbr_fd((token)->id, 1);
		ft_putstr_fd(" \ttoken->id ", 1);
		ft_putstr_fd((token)->context, 1);
		ft_putstr_fd(" \ttoken->type->context ", 1);
		ft_putstr_fd((token)->type, 1);
		ft_putstr_fd(" \t\t\ttoken->type->id ", 1);
		ft_putnbr_fd((token)->type_id, 1);
		ft_putstr_fd(" \t\ttoken->t_flag ", 1);
		ft_putnbr_fd((token)->t_flag, 1);
		ft_putstr_fd("\n", 1);
		token = token->next;
		size++;
	}
	printf("-------------------\n");
	return (size);
}
