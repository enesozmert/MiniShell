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
    print_token(rdl->token);
}

void parser_default(t_rdl *rdl)
{
    int i;
    char **str;

    i = -1;
    str = ft_split(rdl->main_str, ' ');
    while (str[++i])
    {
        rdl->token = token_add(rdl->token, str[i]);
    }
    free(str);
}

t_rdl *parser_analizer(t_rdl *rdl)
{
    int i;
    int s_i;
    t_token *token_zero;

    i = -1;
    s_i = 0;
    token_zero = get_token_id(rdl->token, 0);
    printf("token zero %s\n", token_zero->context);
    keyword_list(rdl->keyword_list);
    while (rdl->keyword_list[++i].type != NULL)
    {
        if (ft_strncmp(rdl->keyword_list[i].type, token_zero->context,
                       ft_strlen(rdl->keyword_list[i].type)) == 0)
        {
            s_i = i;
            break;
        }
    }
    i = 0;
    rdl->keyword_list[s_i].arg =
        ft_strdup(&rdl->main_str[token_zero->len + 1]);
    return (rdl);
}
