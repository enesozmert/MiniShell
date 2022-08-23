#include "../../include/header.h"

void parser_arg_isoperator(char c, int *j, t_rdl *rdl)
{
    int i;

    i = *j;
    if (ft_isalnum(c) || c == ' ')
        rdl->buffer[i++] = c;
    else if ((c != ' ' || c != '\t') && (i != 0))
    {
        rdl->buffer[i] = '\0';
        i = 0;
        parser_add(rdl, rdl->buffer);
    }
    *j = i;
}

void parser_arg_isnotoperator(char c, int *j, t_rdl *rdl)
{
    int i;

    i = *j;
    if (ft_isalnum(c))
        rdl->buffer[i++] = c;
    else if ((c == ' ' || c == '\t') && (i != 0))
    {
        rdl->buffer[i] = '\0';
        i = 0;
        parser_add(rdl, rdl->buffer);
    }
    *j = i;
}

void parser_arg(t_rdl *rdl)
{

    int i;
    int j;
    int flag;
    char c;

    i = -1;
    j = 0;
    flag = 0;
    while (++i < rdl->len)
    {
        c = rdl->main_str[i];
        if (is_operator(rdl, c) == 1)
            flag = 1;
        if (flag == 1)
            parser_arg_isoperator(c, &j, rdl);
        if (flag == 0)
            parser_arg_isnotoperator(c, &j, rdl);
        if (is_operator(rdl, c))
            parser_add_operator(rdl, c);
    }
}