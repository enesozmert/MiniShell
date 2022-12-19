/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:52:59 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 13:54:08 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static void	exception_list(t_exception *excptn)
{
	excptn[0] = (t_exception){100, "0", "quote",
		keyword_quoute_syntax};
	excptn[1] = (t_exception){101, "127", "command not found",
		keyword_syntax};
	excptn[2] = (t_exception){102, "0", "quote",
		quote_syntax};
	excptn[3] = (t_exception){103, "258", "parse error near",
		redir_syntax};
	excptn[4] = (t_exception){104, "1", "export : not a valid identifier",
		export_syntax};
	excptn[5] = (t_exception){105, "258",
		"export : syntax error near unexpected token",
		pipe_syntax};
	excptn[6] = (t_exception){-1, "-1", NULL, NULL};
}

int	exception_handler(t_rdl *rdl)
{
	int			i;
	int			handle_code;
	t_exception	exception[7];

	i = 0;
	handle_code = 0;
	exception_list(exception);
	while (exception[i].message != NULL)
	{
		handle_code = exception[i].f(rdl);
		if (handle_code == exception[i].error_code)
		{
			g_env.exit_status = ft_atoi(exception[i].exit_status);
			exception_write(rdl, exception[i].message);
			return (-1);
		}
		i++;
	}
	return (0);
}
