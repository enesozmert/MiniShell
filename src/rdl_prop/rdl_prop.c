#include "../../include/header.h"

t_rdl_prop *rdl_prop_init(char *str)
{
	int i;
	t_rdl_prop *rdl_prop;
	char **split_str;

	i = 0;
	rdl_prop = malloc(sizeof(t_rdl_prop));
	rdl_prop->main_str = str;
	rdl_prop->len = ft_strlen(rdl_prop->main_str);
	split_str = ft_split(rdl_prop->main_str, ' ');
	while (split_str[i])
		i++;
	rdl_prop->word_count = i;
	rdl_prop->word = malloc(sizeof(t_word) * i + 1);
	i = 0;
	while (split_str[i])
	{
		rdl_prop->word[i].id = i;
		rdl_prop->word[i].str = split_str[i];
		rdl_prop->word[i].len = ft_strlen(split_str[i]);
		i++;
	}
	return (rdl_prop);
}

void rdl_prop_clear(t_rdl_prop *rdl_prop)
{
	int i;

	i = 0;
	while (i < rdl_prop->word_count)
	{
		free(rdl_prop->word[i].str);
		i++;
	}
	free(rdl_prop->main_str);
}

t_word *get_rdl_prop_id(t_rdl_prop *rdl_prop, t_token *token)
{
	int i;
	t_token *token_cpy;

	i = 0;
	token_cpy = token;
	while (token_cpy)
	{
		if (rdl_prop->word[i].id == token_cpy->id)
			return (&rdl_prop->word[i]);
		token_cpy = token_cpy->next;
		i++;
	}
	return (NULL);
}
