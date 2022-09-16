#include "../../include/header.h"

void exception_write(t_rdl *rdl, char *message)
{
    if (rdl->error_arg != 0 && ft_strlen(rdl->error_arg) > 0)
    {
        printf("bash : %s : %s\n", rdl->error_arg, message);
        ft_bzero(rdl->error_arg, ft_strlen(rdl->error_arg));
    }
    else
        printf("bash : %s\n", message);
}