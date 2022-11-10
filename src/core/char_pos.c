#include "../../include/header.h"

int char_pos(t_rdl *rdl, char *str)
{
    char *keyword;
    int i;
    int j;
    int len;

    len = 0;
    i = -1;
    j = 0;
    keyword = malloc(sizeof(char) * rdl->len);
    while (rdl->main_str[i] <= 32 && rdl->main_str[i] != '\0')
		i++;
    while (str[++i] > 32)
    {
        if (str[i] > 32)
            keyword[j++] = str[i];
    }
    keyword[j] = '\0';
    //bu keyword leaks yapar hocam, ileride başımızı ağrıtır
    if (is_keyword(rdl, keyword))
    {
        len = ft_strlen(keyword);
        free(keyword);
        return (len);
    }
    return (0);
}