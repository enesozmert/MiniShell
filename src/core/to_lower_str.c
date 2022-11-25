#include "../../include/header.h"

char *to_lower_str(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        str[i] = ft_tolower(str[i]);
    return (str);
}