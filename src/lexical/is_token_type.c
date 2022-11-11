#include "../../include/header.h"

int is_token_type(t_rdl *rdl, char *str)
{
    int i;

    i = -1;
    
    while (rdl->token_type_list[++i].name != NULL)
    {
        if (ft_strncmp(rdl->token_type_list[i].name, str,
                       ft_strlen(str)) == 0)
            return (1);
    }
    return (0);
}

