#include "../../include/header.h"

t_token *lexical_new(char *context)
{
	t_token *tmp;
	static int id = 0;

	tmp = malloc(sizeof(t_token));
	tmp->id = id;
	id++;
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

void lexical_clear(t_token **token)
{
	t_token	*current;
	t_token	*next;

	if (!token)
		return ;
	current = *token;
	while (current)
	{
		next = current->next;
		lexical_lstdelone(current);
		current = next;
	}
	*token = NULL;
}

void	lexical_lstdelone(t_token *lst)
{
	if (!lst)
		return ;
	free((void *)lst->context);
	free(lst);
}
