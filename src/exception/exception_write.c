#include "../../include/header.h"

void exception_write(t_rdl *rdl, char *message)
{
    if (rdl->error_arg != NULL)
    {
        printf("bash : %s : %s\n", rdl->error_arg, message);
        if(ft_strlen(rdl->error_arg) > 0)
            free(rdl->error_arg);
    }
    else
        printf("bash : %s\n", message);
}