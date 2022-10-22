#include "../../include/header.h"

int env_exist(char *key)
{
    if (env_find_id(key) == -1)
        return (0);
    return (1);
}