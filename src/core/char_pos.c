#include "../../include/header.h"

int char_pos(t_rdl *rdl)
{
    int i;
    int j;
    int total_space;
    int	total_len;
    int	keyword_len;
    char *keyword;

    i = 0;
    j = 0;
    total_space = 0;
	total_len = 0;
	keyword_len = 0;
    keyword = malloc(sizeof(char) * rdl->len);
	while (rdl->main_str[i] <= 32)
	{
		total_space++;
		i++;
	}
	while (rdl->main_str[i] != '\0' && rdl->main_str[i] > 32)
	{
		keyword[j++] = rdl->main_str[i];
		i++;
	}
    keyword[j] = '\0';
	while (rdl->main_str[i] <= 32)
	{
		total_space++;
		i++;
	}
	// printf("keyword: %s\n", keyword);
    // printf("total space : %d\n", total_space);
    if (is_keyword(rdl, keyword))
    {
		keyword_len = ft_strlen(keyword);
		total_len = keyword_len + total_space;
        free(keyword);
        return (total_len);
    }
    return (0);
}