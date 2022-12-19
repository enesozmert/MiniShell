/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:11:59 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 12:12:27 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	exception_write(t_rdl *rdl, char *message)
{
	if (rdl->error_arg != NULL)
	{
		printf("bash: %s: %s\n", rdl->error_arg, message);
		if (rdl->error_arg != NULL)
			ft_bzero(rdl->error_arg, ft_strlen(rdl->error_arg));
	}
	else
		printf("bash : %s\n", message);
}
