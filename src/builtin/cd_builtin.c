/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:33 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/22 22:29:31 by efyaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int cd_home(t_command command)
{
    //command.arg[1] kontrolü yapılacak
    (void)command;
    char *new_dir;

    new_dir = env_find_value("HOME");
    if (chdir(new_dir) == -1)
            return (106);
    return (0);
}

int cd_start(t_command command)
{
    char    *new_dir;
    
    if (command.arg[0] == NULL)
        return(104);
    if (ft_strncmp(command.arg[0], "~", ft_strlen(command.arg[0])) != 0
		&& ft_strncmp(command.arg[0], "$", ft_strlen(command.arg[0])) != 0)
    {
        new_dir = ft_strdup(command.arg[0]);
        if (chdir(new_dir) == -1)
            return (105);
        getcwd(new_dir, sizeof(new_dir));
        free(new_dir);
    }
    if (ft_strncmp(command.arg[0], "~", ft_strlen(command.arg[0])) == 0)
        cd_home(command);
    env_add("OLDPWD", env_find_value("PWD"));
    env_add("PWD", getcwd(NULL, 0));
    return (0);
}