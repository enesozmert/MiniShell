#include "../../include/header.h"

int env_update(char *key, char *str)
{
    (void)str;
    env_find_value(key);
    return (0);
}