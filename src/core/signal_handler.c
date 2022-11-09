#include "../../include/header.h"

void	proc_signal_handler(int signo)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, WNOHANG);
	if (signo == SIGINT)
	{
		if (pid == -1)
		{
			ft_putstr_fd("\b\b  \b\b\n->", 1);
			//global bir exit_status yapıp onu burada -1'e eşitlemek gerekiyor
			//aynı global exit_status'ü tüm hatalı durumlarda(örnek: yanlış komut girilmesi ) değerin değişmesi gerekiyor
			//echo $? ile bu değişkenin güncel hali ekrana yazılacak
		}
		else
			ft_putstr_fd("2", 1);
/* 
		ft_putstr_fd("\n", 1);
		signal(SIGINT, proc_signal_handler); */
	}
	else if (signo == SIGQUIT)
	{
		if (pid == -1)
			ft_putstr_fd("3", 1);
		else
			ft_putstr_fd("Quit: 3\n", 1);
	}
}

void set_signal()
{
	signal(SIGINT, proc_signal_handler);
	signal(SIGQUIT, proc_signal_handler);
}