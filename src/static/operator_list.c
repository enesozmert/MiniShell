#include "../../include/header.h"

void	operator_list(t_operator *operator)
{
	operator[0] = (t_operator){"single_quote" ,"\'", 0, single_quote};
	operator[1] = (t_operator){"double_quote" ,"\"", 0, NULL};
	operator[2] = (t_operator){"redirect_in" ,"<", 0, NULL};
	operator[3] = (t_operator){"redirect_out" ,">", 0, NULL};
	operator[4] = (t_operator){"varible" ,"$", 0, NULL};
	operator[5] = (t_operator){"pipe" ,"|", 0, NULL};
	operator[6] = (t_operator){"and" ,"&", 0, NULL};
	operator[7] = (t_operator){NULL ,NULL, 0, NULL};
}