#include "../../include/header.h"

void	operator_list(t_operator *operator)
{
	operator[0] = (t_operator){"redirect_in" ,"<"};
	operator[1] = (t_operator){"redirect_out" ,">"};
	operator[2] = (t_operator){"varible" ,"$"};
	operator[3] = (t_operator){"pipe" ,"|"};
	operator[4] = (t_operator){"and" ,"&"};
	operator[5] = (t_operator){"equal" ,"="};
	operator[6] = (t_operator){NULL ,NULL};
}