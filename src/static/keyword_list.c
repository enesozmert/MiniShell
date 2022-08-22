#include "../../include/header.h"

void	keyword_list(t_keyword *keyword)
{
	keyword[0] = (t_keyword){"echo", NULL};
	keyword[1] = (t_keyword){"cd", NULL};
	keyword[2] = (t_keyword){"pwd", NULL};
	keyword[3] = (t_keyword){"export", NULL};
	keyword[4] = (t_keyword){"unset", NULL};
	keyword[5] = (t_keyword){"env", NULL};
	keyword[6] = (t_keyword){"exit", NULL};
	keyword[7] = (t_keyword){NULL, NULL};
}