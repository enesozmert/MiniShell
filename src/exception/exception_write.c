#include "../../include/header.h"

void exception_write(t_rdl *rdl, char *message)
{
    //printf("\nexception_write func: %s %d\n", rdl->error_arg, ft_strncmp(rdl->error_arg, "quote", 4));
    if (rdl->error_arg != NULL)
    {
        printf("bash : %s : %s\n", rdl->error_arg, message);
        if(ft_strlen(rdl->error_arg) > 0)
            free(rdl->error_arg);
        // free(rdl->error_arg);
        //ft_bzero(rdl->error_arg, ft_strlen(rdl->error_arg));
    }
    else
        printf("bash : %s\n", message);
}