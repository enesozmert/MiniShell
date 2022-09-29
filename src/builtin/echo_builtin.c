#include "../../include/header.h"

int echo_start(t_command command)
{
    int i;
    int arg_count;

    i = 0;
    arg_count = command.arg_count;
    while (i < arg_count)
    {
        printf("%s", command.arg[i]);
        if(i < arg_count)
            printf(" ");
        i++;
    }
    printf("\n");
    return (0);
}

//end
//exception
//re