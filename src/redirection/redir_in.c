/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:03:29 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/12 17:41:36 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int redir_in_exec(t_command command)
{
    int fd_file;

    fd_file = redir_out_exec(command);
    printf("file_fd %d\n", fd_file);
    return (fd_file);
}