/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:33 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/19 12:28:53 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static int cd_home(t_command command)
{
    (void)command;
    char *new_dir;

    new_dir = env_find_value("HOME");
    if (chdir(new_dir) == -1)
        return (205);
    return (0);
}

static int cd_key(t_command command)
{
    char    *new_dir;
    
    new_dir = env_find_value(command.tokens->context);
    if (chdir(new_dir) == -1)
        return (205);
    getcwd(new_dir, sizeof(new_dir));
    return (0);
}

static int cd_arg(t_command command)
{
    char    *new_dir;

    if (ft_strncmp(command.tokens->context, "~", ft_strlen(command.tokens->context)) == 0)
    {
        cd_home(command);
        return (0);
    }
    new_dir = ft_strdup(command.tokens->context);
    if (chdir(new_dir) == -1)
        return (205);
    getcwd(new_dir, sizeof(new_dir));
    free(new_dir);
    return (0);
}

int cd_start(t_command command)
{
    int i;
    int size;
    int error;

    error = 0;
    i = -1;
    size = token_size(command.tokens);
    if (size == 0)
        cd_home(command);
    while (++i < size)
    {
        if (command.tokens->type_id == 8)
            error = cd_key(command);
        if (command.tokens->type_id == 11)
            error = cd_arg(command);
        get_next_token(&command.tokens);
    }

    if (error == 205)
        return (205);
    env_add("OLDPWD", env_find_value("PWD"));
    env_add("PWD", getcwd(NULL, 0));
    return (0);
}