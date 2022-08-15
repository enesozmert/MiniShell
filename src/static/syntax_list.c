#include "../../include/header.h"

void	syntax_list(t_syntax *syntax)
{
	syntax[0] = (t_syntax){"single_quote" ,"'", NULL};
	syntax[1] = (t_syntax){"double_quote" ,"\"", NULL};
	syntax[2] = (t_syntax){"redirect_in" ,"<", NULL};
	syntax[3] = (t_syntax){"redirect_out" ,">", NULL};
	syntax[4] = (t_syntax){"redirect_add_in" ,"<<", NULL};
	syntax[5] = (t_syntax){"redirect_add_out" ,">>", NULL};
	syntax[6] = (t_syntax){"space" ," ", NULL};
	syntax[7] = (t_syntax){"varible" ,"$", NULL};
	syntax[8] = (t_syntax){"pipe" ,"|", NULL};
	syntax[9] = (t_syntax){NULL ,NULL, NULL};
}