#include "../../include/header.h"

int echo_start(t_command command, t_rdl *rdl)
{
    int i;
    int arg_count;

    i = 0;
    arg_count = token_arg_count(rdl->token);
    printf("arg_count : %d\n", arg_count);
    while (i < arg_count)
    {
        printf("%s", command.arg[i]);
        i++;
    }
    printf("\n");
    return (0);
}

//end
//exception
//re