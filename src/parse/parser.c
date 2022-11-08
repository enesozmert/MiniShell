#include "../../include/header.h"

void parser(t_rdl *rdl)
{
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
