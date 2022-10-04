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
        parser_arg(rdl);
    
    t_token *tkn;
    tkn = rdl->token;
    //while(tkn->context)
    //{
        token_add_index(&tkn);
	    token_add_type(&tkn);
     //   get_next_token(&tkn);
    //}
    print_token(rdl->token);
}

void parser_default(t_rdl *rdl)
{
    int i;
    char **str;

    i = -1;
    str = ft_split(rdl->main_str, ' ');
    while (str[++i])
        rdl->token = token_add(rdl->token, str[i], 0);
    free(str);
}
