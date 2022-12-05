/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:03:17 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/05 18:02:18 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int redir_file_create(t_command command, char *name)
{
    int fd;

    fd = 0;
    if (command.token_sub_type_id == 0)
        fd = open(name, O_CREAT | O_TRUNC | O_RDWR, 0777);
    if (command.token_sub_type_id == 2)
        fd = open(name, O_RDONLY | O_RDWR, 0777);
    return (fd);
}