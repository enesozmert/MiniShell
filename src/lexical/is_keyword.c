#include "../../include/header.h"

int is_keyword(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    while (rdl->keyword_list[++i].type != NULL)
    {
        if (ft_strnstr(rdl->keyword_list[i].type, str,
        ft_strlen(rdl->keyword_list[i].type)) != NULL)
            return (1);
    }
    return (0);
}
