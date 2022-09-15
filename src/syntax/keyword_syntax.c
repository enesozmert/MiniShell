#include "../../include/header.h"

int keyword_syntax(t_rdl *rdl, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_tolower(str[i]);
	// printf("qc %d\n", quote_count(str, '\"'));
	if (quote_count(str, '\"') % 2 != 0 || quote_count(str, '\'') % 2 != 0)
		return (0);
	str = keyword_trim(str);
    if (is_keyword(rdl, str))
        return (1);
    return (0);
}
