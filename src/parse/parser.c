#include "../../include/header.h"

void parser(t_rdl *rdl)
{
    char *result;
    int i;

    i = -1;
    result = 0;
    while (rdl->operator_list[++i].name != NULL)
    {
        result = ft_strchr(rdl->main_str, rdl->operator_list[i].sybl[0]);
        if (result != NULL)
            break ;
    }
    if (result == NULL)
        parser_default(rdl);
    else
        parser_arg_split(rdl);
    print_token(rdl->token);
}

void parser_default(t_rdl *rdl)
{
    int i;
    char **str;

    i = -1;
    str = ft_split(rdl->main_str, ' ');
    while (str[++i])
        rdl->token = token_add(rdl->token, str[i]);
    free(str);
}
