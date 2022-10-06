/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:52:59 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/06 15:07:36 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	exception_handler(t_rdl *rdl)
{
	int			i;
	int			handle_code;
	t_exception	exception[5];

	i = 0;
	handle_code = 0;
	exception[0] = (t_exception){100, "quote", keyword_quoute_syntax};
	exception[1] = (t_exception){101, "command not found", keyword_syntax};
	exception[2] = (t_exception){102, "quote", quote_syntax};
	exception[3] = (t_exception){103, "parse error near", redir_syntax};
	exception[4] = (t_exception){-1, NULL, NULL};
	while (exception[i].message != NULL)
	{
		handle_code = exception[i].f(rdl);
		if (handle_code == exception[i].error_code)
		{
			exception_write(rdl, exception[i].message);
			rl_on_new_line();
			return (-1);
		}
		i++;
	}
	return (0);
}