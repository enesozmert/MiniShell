/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:56:46 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 16:57:53 by cyalniz          ###   ########.fr       */
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
	if (ft_strncmp(rdl->token->type, "invalid_identifier",
			ft_strlen(rdl->token->type)) == 0)
	{
		error_arg = ft_strjoin("`", rdl->token->context);
		error_arg = ft_strjoin(error_arg, "'");
		rdl->error_arg = ft_strdup(error_arg);
		return (104);
	}
	return (0);
}
