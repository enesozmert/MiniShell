#include "../../include/header.h"

// static int echo_key(t_command command)
// {
//     int i;
//     int key_count;
//     char *env_value;

//     i = -1;
//     env_value = NULL;
//     key_count = command.key_count;
//     while (++i < key_count)
//     {
//         env_value = env_find_value(command.key[i]);
//         printf("%s", env_value);
// 		if (!env_value)
//         	free(env_value);
//     }
//     return (0);
// }

// static int echo_value(t_command command)
// {
//     int i;
//     int value_count;

//     value_count = command.value_count;
//     i = -1;
//     while (++i < value_count)
//         printf("%s", command.value[i]);
//     printf("\n");
//     return (0);
// }

int echo_start(t_command command)
{
    (void)command;
    // echo_key(command);
    // echo_value(command);
    return (0);
}

// key
// value
// end
// exception
// re