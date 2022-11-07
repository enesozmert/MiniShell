#include "../../include/header.h"

int is_identifier(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    while (rdl->identifier_list[++i].sybl != NULL)
    {
        if (rdl->identifier_list[i].sybl[0] == str[0]
            || is_delimiter(rdl, str[0]))
            return (0);
    }
    return (1);
}