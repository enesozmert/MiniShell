#include "../../include/header.h"

t_token *lexical_new(char *context)
{
	t_token *tmp;

	tmp = malloc(sizeof(t_token));
	tmp->context = context;
	tmp->next = NULL;
	return (tmp);
}

t_token *lexical_last(t_token *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void lexical_append(t_token **lst, t_token *new)
{
	t_token *tmp;

	if (!*lst)
	{
		*lst = new;
		return;
	}
	tmp = lexical_last(*lst);
	tmp->next = new;
}

t_token *lexical_add(t_token *lst, char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		lexical_append(&lst, lexical_new(ptr[i]));
		i++;
	}
	return (lst);
}

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
