/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:12:16 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/02 17:41:41 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	redir_list(t_redir *redir)
{
	redir[0] = (t_redir){">"};
	redir[1] = (t_redir){">>"};
	redir[2] = (t_redir){"<"};
	redir[3] = (t_redir){"<<"};
	redir[4] = (t_redir){NULL};
}