#include "../../include/header.h"

int unset_start(t_command command)
{
    env_delete(command.arg[0]);
    return (0);
}