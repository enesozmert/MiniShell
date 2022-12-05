/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:58:40 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/05 12:48:12 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char *redir_file_name(t_command command)
{
    int i;
    char *file_name;

    i = -1;
    file_name = ft_strdup("");
    while (++i < command.token_size)
    {
        if (command.tokens->type_id == 12)
            file_name = ft_strjoin(file_name, command.tokens->context);
        get_next_token(&command.tokens);
    }
    return (file_name);
}