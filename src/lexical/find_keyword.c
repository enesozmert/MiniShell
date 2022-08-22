#include "../../include/header.h"

t_keyword find_keyword(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    while (rdl->keyword_list[++i].type != NULL)
    {
        if (ft_strnstr(rdl->keyword_list[i].type, str,
        ft_strlen(rdl->keyword_list[i].type)))
            return (rdl->keyword_list[i]);
    }
    return (rdl->keyword_list[7]);
}