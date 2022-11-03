#include "../../include/header.h"

int keyword_in_operator(t_rdl *rdl, char *str, char operator)
{
    int			i;
    char		**operators_id;
	int			operator_id;
    t_keyword	keyword;

    i = -1;
	operator_id = -1;
    keyword = find_keyword(rdl, str);
    operators_id = ft_split(keyword.operators_id, ',');
	printf("operators id : %s\n", operators_id[0]);
	while (rdl->operator_list[++operator_id].name != NULL)
	{
		if (rdl->operator_list[operator_id].sybl[0] == operator)
            break ;
	}
	printf("operator id : %d\n", operator_id);
    while (operators_id[++i])
    {
        if (operator_id == ft_atoi(operators_id[i]))
            return (1);
    }
    return (0);
}