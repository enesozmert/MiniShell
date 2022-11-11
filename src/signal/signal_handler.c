#include "../../include/header.h"

void	proc_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		signal(SIGINT, proc_signal_handler);
	}
}

void set_signal()
{
	signal(SIGINT, proc_signal_handler);
	signal(SIGQUIT, proc_signal_handler);
}