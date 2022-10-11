/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:33 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/06 22:12:06 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int cd_start(t_command command)
{
    char *new_dir;
    
    if (command.arg[0] == NULL)
        return(105);
    new_dir = ft_strdup(command.arg[0]);
    if (chdir(new_dir) == -1)
        return (104);
    else
        getcwd(new_dir, sizeof(new_dir));
    free(new_dir);
    return (0);
}