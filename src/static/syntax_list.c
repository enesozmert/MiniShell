#include "../../include/header.h"

void	syntax_list(t_syntax *syntax)
{
	syntax[0] = (t_syntax){"single_quote" ,"\'", 0, single_quote};
	syntax[1] = (t_syntax){"double_quote" ,"\"", 0, NULL};
	syntax[2] = (t_syntax){"redirect_in" ,"<", 0, NULL};
	syntax[3] = (t_syntax){"redirect_out" ,">", 0, NULL};
	syntax[4] = (t_syntax){"redirect_add_in" ,"<<" , 0, NULL};
	syntax[5] = (t_syntax){"redirect_add_out" ,">>", 0, NULL};
	syntax[6] = (t_syntax){"space" ," ", 0, NULL};
	syntax[7] = (t_syntax){"varible" ,"$", 0, NULL};
	syntax[8] = (t_syntax){"pipe" ,"|", 0, NULL};
	syntax[9] = (t_syntax){NULL ,NULL, 0, NULL};
}