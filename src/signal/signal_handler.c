/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:53:17 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 14:53:47 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
		signal(SIGINT, proc_signal_handler);
}

void	interrupt_here_document(int signo)
{
	(void)signo;
	write(1, "\n", 1);
	exit(130);
}

void	set_signal(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		signal(SIGINT, set_signal);
	}
	if (signo == SIGQUIT)
	{
		signal(SIGINT, set_signal);
		signal(SIGQUIT, set_signal);
	}
}
