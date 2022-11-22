#include "../../include/header.h"

int find_keyword_id(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    while (rdl->keyword_list[++i].type != NULL)
    {
        if (ft_strnstr(rdl->keyword_list[i].type, str,
        ft_strlen(rdl->keyword_list[i].type)))
            return (i);
    }
    return (-1);
}
