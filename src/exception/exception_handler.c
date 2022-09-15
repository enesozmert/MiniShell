#include "../../include/header.h"

void	exception_handler(t_rdl *rdl)
{
	int			i;
	int			handle_code;
	t_exception	exception[3];

	i = 0;
	handle_code = 0;
	exception[0] = (t_exception){100, "Quote", keyword_quoute_syntax};
	exception[1] = (t_exception){101, "Command Not Found", keyword_syntax};
	exception[2] = (t_exception){-1, NULL, NULL};
	while (exception[i].message != NULL)
	{
		handle_code = exception[i].f(rdl);
		if (handle_code == exception[i].error_code)
			printf("Error : %s\n", exception[i].message);
		i++;
	}
}