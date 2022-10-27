#include "../../include/header.h"

void parser(t_rdl *rdl)
{
    // char    *result;
    // char    *result1;
    // int i;

    // i = -1;
    // result = 0;
    // result1 = 0;
    // while (rdl->quote_list[++i].name != NULL)
    // {
    //     result = ft_strchr(rdl->main_str, rdl->quote_list[i].sybl[0]);
    //     if (result != NULL)
    //         break ;
    // }
    // i = -1;
    // while (rdl->operator_list[++i].name != NULL)
    // {
    //     result1 = ft_strchr(rdl->main_str, rdl->operator_list[i].sybl[0]);
    //     if (result1 != NULL)
    //         break ;
    // }
    // if (result == NULL)
    //     parser_default(rdl);
    // else
    parser_arg(rdl);
    token_add_type(&rdl->token);
    print_token(rdl->token);
}

void parser_default(t_rdl *rdl)
{
    int i;
    char **str;

    i = -1;
    str = ft_split(rdl->main_str, ' ');
    printf("%s\n", str[0]);
    while (str[++i])
        rdl->token = token_add(rdl->token, str[i], 0);
    free(str);
}
