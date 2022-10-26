#include "../../include/header.h"

int command_fork(int (*f)(struct s_command))
{
    pid_t   pid;
    int     handle_code;

    handle_code = 0;
    pid = fork();
    signal(SIGINT, proc_signal_handler);
    if (pid == 0)
        handle_code = f(command);
    else if (pid < 0)
        return (-1);
    wait(&pid);
    return (handle_code);
}
