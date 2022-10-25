#include "../../include/header.h"

int export_start(t_command command)
{
    char    *key;
    char    *value;

    key = ft_strdup(command.arg[0]);
    value = ft_strdup(command.arg[1]);
    env_add(key, value);
    // env_asc(g_env.env);
    free(key);
    free(value);
    return (0);
}
