/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:03:43 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/15 20:30:48 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static char *export_key(t_command command, char *value)
{
	char *key;
	char *join_value;
	char *tmp_value;
	
	key = NULL;
	tmp_value = NULL;
	join_value = ft_strdup(value);
	if (command.tokens->type_id == 10)
	{
		key = ft_strdup(command.tokens->context);
		tmp_value = env_find_value(key);
		if (tmp_value)
		{
			value = ft_strjoin(join_value, tmp_value);
			free(key);
		}
	}
	free(join_value);
	return (join_value);
}

static char *export_value(t_command command, char *value)
{
	char *join_value;
	
	join_value = ft_strdup(value);
	if (command.tokens->type_id == 11)
		value = ft_strjoin(join_value, command.tokens->context);
	free(join_value);
	return (value);
}

static char *export_identifer(t_command command, char *identifier)
{
	if (command.tokens->type_id == 8)
		identifier = ft_strdup(command.tokens->context);
	return (identifier);
}

int export_start(t_command *command)
{
	int i;
	int size;
	char *value;
	char *identifier;

	i = -1;
	value = ft_strdup(value);
	identifier = NULL;
	size = token_size(command->tokens);
	if (size == 0)
	{
		env_asc(g_env.env);
		while (g_env.env[++i])
			printf("declare -x %s\n", g_env.env[i]);
	}
	i = -1;
	while (++i < size)
	{
		identifier = export_identifer(*command, identifier);
		value = export_key(*command, value);
		value = export_value(*command, value);
		if (command->tokens->type_id == 12 || size == i + 1)
		{
			printf("iden : %s\n", identifier);
			printf("value : %s\n", value);
			env_add(identifier, value);
			free(value);
			value = ft_strdup("");
		}
		get_next_token(&command->tokens);
	}
	free(value);
	free(identifier);
	return (0);
}
