#include "../../include/header.h"

int echo_start(t_command command)
{
    // (void)command;
    int i;
    int arg_count;

    i = -1;
    arg_count = 2;
    while (++i < arg_count)
    {
        printf("%s\n", command.arg[i]);
    }
    return (0);
}

//end
//exception
//re