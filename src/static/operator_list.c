#include "../../include/header.h"

void	operator_list(t_operator *operator)
{
	operator[0] = (t_operator){"pipe" ,"|"};
	operator[1] = (t_operator){"and" ,"&"};
	operator[2] = (t_operator){"equal" ,"="};
	operator[3] = (t_operator){NULL ,NULL};
}