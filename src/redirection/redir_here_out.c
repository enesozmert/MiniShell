#include "../../include/header.h"

int redir_here_out_exec(t_command command)
{
    int fd_file;

    fd_file = redir_out_exec(command);
    return (fd_file);
}