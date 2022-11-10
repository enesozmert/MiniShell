#include "../../include/header.h"

int char_pos(t_rdl *rdl, char *str)
{
    char *keyword;
    int i;
    int j;

    i = -1;
    j = 0;
    keyword = malloc(sizeof(char) * rdl->len);
    while (rdl->main_str[i] <= 32 )
		i++;
    while (str[++i])
    {
        if (str[i] > 32 && str[i + 1] <= 32)
            keyword[j++] = str[i];
    }
    keyword[j] = '\0';
    printf("keyword: %s\n", keyword);
    if (is_keyword(rdl, keyword))
        return (ft_strlen(keyword) - 1);
    return (0);
}