#include "../../include/header.h"

void	keyword_list(t_keyword *keyword)
{
	keyword[0] = (t_keyword){"echo"};
	keyword[1] = (t_keyword){"cd"};
	keyword[2] = (t_keyword){"pwd"};
	keyword[3] = (t_keyword){"export"};
	keyword[4] = (t_keyword){"unset"};
	keyword[5] = (t_keyword){"env"};
	keyword[6] = (t_keyword){"exit"};
	keyword[7] = (t_keyword){NULL};
}