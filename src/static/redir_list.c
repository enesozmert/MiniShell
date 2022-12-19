/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:12:16 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 10:27:27 by cyalniz          ###   ########.fr       */
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
