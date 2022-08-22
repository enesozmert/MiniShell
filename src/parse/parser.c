#include "../../include/header.h"

static void parser_default(t_rdl *rdl)
{
    int i;
    int j;
    char c;
    char *buffer;

    i = -1;
    j = 0;
    buffer = malloc(sizeof(char) * 30);
    while (++i < rdl->len)
    {
        c = rdl->main_str[i];
        if (ft_isalnum(c) || is_indentifier(rdl, c))
            buffer[j++] = c;
        else if ((c != ' ' || c != '\t') && (j != 0))
        {
            buffer[j] = '\0';
            j = 0;
            parser_add(rdl, buffer);
        }
        if (is_operator(rdl, c))
            parser_add_operator(rdl, c);
    }
}

static void parser_arg(t_rdl *rdl)
{

    int i;
    int j;
    int flag = 0;
    char c;
    char *buffer;

    i = -1;
    j = 0;
    c = ' ';
    buffer = malloc(sizeof(char) * 30);
    while (i++ < rdl->len)
    {
        c = rdl->main_str[i];
        if (is_operator(rdl, c) == 1)
            flag = 1;
        if (flag == 1)
        {
            if (ft_isalnum(c) || c == ' ' || is_indentifier(rdl, c))
                buffer[j++] = c;
            else if ((c != ' ' || c != '\t') && (j != 0))
            {
                buffer[j] = '\0';
                j = 0;
                parser_add(rdl, buffer);
            }
        }
        if (flag == 0)
        {
            if (ft_isalnum(c) || is_indentifier(rdl, c))
                buffer[j++] = c;
            else if ((c != ' ' || c != '\t') && (j != 0))
            {
                buffer[j] = '\0';
                j = 0;
                parser_add(rdl, buffer);
            }
        }
        if (is_operator(rdl, c))
            parser_add_operator(rdl, c);
    }
}

void parser(t_rdl *rdl)
{
    char *result;
    int i;

    i = -1;
    result = 0;
    while (rdl->operator_list[++i].name != NULL)
        result = ft_strchr(rdl->main_str, rdl->operator_list[i].sybl[0]);
    if (result == 0)
        parser_arg(rdl);
    else
        parser_default(rdl);
    print_token(rdl->token);
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
