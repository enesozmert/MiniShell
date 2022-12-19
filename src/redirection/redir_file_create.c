/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:03:17 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 12:57:53 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	redir_file_create(t_command *command, char *name)
{
	int	fd;

	fd = 0;
	if (command->token_sub_type_id == 0)
		fd = open(name, O_CREAT | O_TRUNC | O_RDWR, 0777);
	if (command->token_sub_type_id == 1)
		fd = open(name, O_CREAT | O_APPEND | O_RDWR, 0777);
	if (command->token_sub_type_id == 2)
		fd = open(name, O_CREAT | O_RDONLY, 0777);
	if (command->token_sub_type_id == 3)
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	return (fd);
}
