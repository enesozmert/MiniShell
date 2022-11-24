/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:58:27 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/24 20:06:21 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int is_redir(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    while (rdl->redir_list[++i].sybl != NULL)
    {
        if (rdl->redir_list[i].sybl[0] == str[0])
            return (0);
    }
    return (1);
}