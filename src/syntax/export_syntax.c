/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:56:46 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/13 12:24:49 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	export_syntax(t_rdl *rdl)
{
	char	*error_arg;

	error_arg = NULL;
	if (ft_strncmp(rdl->token->context, "export",
			rdl->token->len) == 0)
		return (0);
	if (rdl->token->type_id == 9)
	{
		error_arg = ft_strjoin("`", rdl->token->context);
		error_arg = ft_strjoin(error_arg, "'");
		rdl->error_arg = ft_strdup(error_arg);
		return (104);
	}
	return (0);
}
