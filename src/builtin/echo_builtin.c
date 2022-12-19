/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:00:48 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 12:51:16 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int echo_dollar(t_command *command)
{
	if (!command->tokens->next)
		ft_putstr_fd(command->tokens->context, command->file_fd);
	else if (command->tokens->next->type_id == 2)
		ft_putstr_fd(command->tokens->context, command->file_fd);

	return (0);
}

static int echo_key(t_command *command)
{
	char *env_value;

	env_value = env_find_value(command->tokens->context);
	if (env_value != NULL)
		ft_putstr_fd(env_value, command->file_fd);
	if (command->tokens->context[0] == '?' && ft_strlen(command->tokens->context) == 1)
	{
		ft_putnbr_fd(g_env.exit_status, command->file_fd);
		return (0);
	}
	return (0);
}

static int echo_string(t_command *command, int n_flag)
{
	if (n_flag == 1 && command->tokens->context[0] == 'n')
		return (0);
	ft_putstr_fd(command->tokens->context, command->file_fd);
	return (0);
}

static int echo_new_line(t_command *command)
{
	if (command->tokens->next->context[0] == 'n' && command->tokens->id == 0)
		return (1);
	else
		ft_putstr_fd(command->tokens->context, command->file_fd);
	return (0);
}

int echo_start(t_command *command)
{
	int i;
	int size;
	int n_flag;

	i = -1;
	size = token_size(command->tokens);
	n_flag = 0;
	while (++i < size)
	{
		if (command->tokens->type_id == 3)
			echo_dollar(command);
		if (command->tokens->type_id == 7)
			n_flag = echo_new_line(command);
		if (command->tokens->type_id == 10)
			echo_key(command);
		if (command->tokens->type_id == 12 || command->tokens->type_id == 14)
			echo_string(command, n_flag);
		if (n_flag == 1 && command->tokens->context[0] == 'n')
			get_next_token(&command->tokens);
		get_next_token(&command->tokens);
	}
	if (n_flag == 0)
		ft_putstr_fd("\n", command->file_fd);
	return (0);
}
