#include "../../include/header.h"

void	quote_list(t_quote *quote)
{
	quote[0] = (t_quote){"single_quote", "\'"};
	quote[1] = (t_quote){"double_quote", "\""};
	quote[2] = (t_quote){NULL, NULL};
}