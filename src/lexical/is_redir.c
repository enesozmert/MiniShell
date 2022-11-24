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

int is_redir(t_rdl *rdl, char c)
{
    int i;

    i = -1;
    printf("redir : %c\n", c);
    while (rdl->redir_list[++i].sybl != NULL)
    {
        if (rdl->redir_list[i].sybl[0] == c)
            return (1);
    }
    return (0);
}