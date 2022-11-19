#include "../../include/header.h"

// typedef struct s_signal
// {
// 	int sig;
// 	int (*f)(t_signal *);
// } t_signal;

// static void	signal_list(t_signal *signo)
// {
// 	signo[0] = (t_signal){2, f_sig_int};
// 	signo[1] = (t_signal){3, f_sig_quit};
// 	signo[2] = (t_signal){-1, NULL};
// }

void proc_signal_handler(int signo)
{
	// pid_t	pid;
	// int		i;
	// int		status;

	// i = -1;
	// pid = waitpid(-1, &status, WNOHANG);
	// while(rdl->signal_list[i].sig != -1)
	// {
	// 	if (rdl->signal_list[i].sig == signo)
	// 		rdl->signal_list[i].f(rdl->signal_list[i]);
	// 	i++;
	// }
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