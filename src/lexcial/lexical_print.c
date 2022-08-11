#include "../../include/header.h"

int print_lexical(t_token *token)
{
	int size;

	size = 0;
	printf("-------------------\n");
	while (token)
	{
		printf("%s\n", (token)->context);
		token = token->next;
		size++;
	}
	printf("-------------------\n");
	return (size);
}
