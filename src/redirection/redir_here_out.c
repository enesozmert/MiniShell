#include "../../include/header.h"

int redir_here_out_exec(t_command command)
{
    int fd_file;
    char *file_name;

    printf("redir here out create\n");
    fd_file = 0;
    if (command.count < command.redir_count + 1 && command.count > 1)
    {
        file_name = redir_file_name(command);
        printf("file name : %s\n", file_name);
        fd_file = redir_file_create(command, file_name);
        close(fd_file);
    }
    else if (command.count == command.redir_count + 1 && command.count > 1)
    {
        file_name = redir_file_name(command);
        printf("file name : %s\n", file_name);
        fd_file = redir_file_create(command, file_name);
    }
    return (fd_file);
}