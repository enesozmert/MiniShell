#include "../../include/header.h"

int redir_here_out_exec(t_command *command)
{
    int fd_file;
    char *file_name;
    
    file_name = redir_file_name(command);
    printf("file name2 : %s\n", file_name);
    fd_file = redir_file_create(command, file_name);
    return (fd_file);
}