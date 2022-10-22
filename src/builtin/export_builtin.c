#include "../../include/header.h"

int export_start(t_command command)
{
    char    *key;
    char    *value;

    key = ft_strdup(command.arg[0]);
    value = ft_strdup(command.arg[1]);
    env_add(key, value);
    free(key);
    free(value);
    return (0);
}
