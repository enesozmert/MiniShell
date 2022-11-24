/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:12:16 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/24 19:15:31 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	redir_list(t_identifier *identifier)
{
	identifier[0] = (t_identifier){"0"};
	identifier[1] = (t_identifier){"1"};
	identifier[2] = (t_identifier){"2"};
	identifier[3] = (t_identifier){"3"};
	identifier[4] = (t_identifier){NULL};
}