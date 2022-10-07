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
    new_dir = malloc(sizeof(char) * ft_strlen(command.arg[0]));
    printf("command.arg[0] %s\n", command.arg[0]);
    new_dir = command.arg[0];

    if (chdir(new_dir) != 0)
<<<<<<< HEAD
        return (104);
=======
        return (104); 
    //chdir(new_dir);
>>>>>>> d307dff4068ba0dae89005121c5604e40cd58d3f
    printf("cd_start: %s\n", new_dir);
    getcwd(new_dir, sizeof(new_dir));
    printf("\nDir: %s\n", new_dir);
    free(new_dir);
    return (0);
}