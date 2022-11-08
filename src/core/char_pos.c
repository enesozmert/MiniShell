#include "../../include/header.h"

int char_pos(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (str[i] <= 32 && str[i + 1] > 32)
        {
            return (i + 1);
        }
    }
    return (0);
}
