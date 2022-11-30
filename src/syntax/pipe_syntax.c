/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:58:01 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 16:58:31 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	pipe_syntax(t_rdl *rdl)
{
	if (rdl->token->id == 0)
		return (0);
	if (rdl->pipe_prop->count > 2)
		return (105);
	return (0);
}
