#include "../../include/header.h"

int echo_start(t_command command)
{
    int i;
    int arg_count;

    i = -1;
    arg_count = 2;
    while (++i < arg_count)
    {
        printf("%s", command.arg[0]);
    }
    printf("\n");
    return (0);
}

//end
//exception
//re