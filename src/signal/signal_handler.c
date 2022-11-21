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
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		signal(SIGINT, proc_signal_handler);
	}
}

void set_signal(int signo)
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
		printf("enes\n");
		signal(SIGINT, set_signal);
		signal(SIGQUIT, set_signal);
	}
}