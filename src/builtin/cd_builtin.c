/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:33 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 11:59:03 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int	cd_home(t_command command)
{
	(void)command;
	char	*new_dir;

	new_dir = env_find_value("HOME");
	if (chdir(new_dir) == -1)
		return (205);
	return (0);
}

static int	cd_key(t_command command)
{
	char	*new_dir;

	new_dir = env_find_value(command.tokens->context);
	if (chdir(new_dir) == -1)
		return (205);
	getcwd(new_dir, sizeof(new_dir));
	return (0);
}

static int	cd_arg(t_command command, char *new_dir)
{
	if (ft_strncmp(command.tokens->context, "~",
			ft_strlen(command.tokens->context)) == 0)
	{
		cd_home(command);
		return (0);
	}
	if (chdir(new_dir) == -1)
		return (205);
	getcwd(new_dir, sizeof(new_dir));
	return (0);
}

static void	cd_update(char *new_dir)
{
	char	*pwd;

	pwd = NULL;
	env_add("OLDPWD", env_find_value("PWD"));
	pwd = getcwd(NULL, 0);
	env_add("PWD", pwd);
	free(pwd);
	free(new_dir);
}

int	cd_start(t_command *command)
{
	int		i;
	int		error;
	char	*new_dir;

	i = -1;
	error = 0;
	new_dir = NULL;
	if (command->token_size == 0)
		cd_home(*command);
	while (++i < command->token_size)
	{
		if (command->tokens->type_id == 10)
			error = cd_key(*command);
		if (command->tokens->type_id == 13 || command->tokens->type_id == 12)
		{
			new_dir = s1free_join(new_dir, command->tokens->context);
			error = cd_arg(*command, new_dir);
		}
		get_next_token(&command->tokens);
	}
	cd_update(new_dir);
	if (error == 205)
		return (205);
	return (0);
}
