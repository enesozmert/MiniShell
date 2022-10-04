/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:33 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/04 15:01:15 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int cd_start(t_command command)
{
    char *new_dir;
    new_dir = ft_strdup(*command.arg);

    chdir(new_dir);
/*     printf("cd_start: %s\n", new_dir);
    getcwd(new_dir, sizeof(new_dir));
	printf("\nDir: %s\n", new_dir); */
    //free(new_dir);  
    return (0);
}