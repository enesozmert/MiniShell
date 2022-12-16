/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:03:29 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/16 03:24:00 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int redir_in_exec(t_command *command)
{
    int fd_file;
    char *file_name;
    
    file_name = redir_file_name(command);
    printf("file name2 : %s\n", file_name);
    fd_file = redir_file_create(command, file_name);
    free(file_name);
    return (fd_file);
}