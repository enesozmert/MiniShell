#include "../../include/header.h"

int char_pos(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    if (is_keyword(rdl, str))
        return (ft_strlen(str));
    while (str[++i])
    {
        if (str[i] <= 32 && str[i + 1] > 32)
        {
            return (i + 1);
        }
    }
    return (0);
}
