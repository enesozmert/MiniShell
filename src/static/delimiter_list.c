#include "../../include/header.h"

void	delimiter_list(t_delimiter *delimiter)
{
	delimiter[0] = (t_delimiter){" "};
	delimiter[1] = (t_delimiter){"+"};
	delimiter[2] = (t_delimiter){"-"};
	delimiter[3] = (t_delimiter){"*"};
	delimiter[4] = (t_delimiter){"/"};
	delimiter[5] = (t_delimiter){","};
	delimiter[6] = (t_delimiter){";"};
	delimiter[7] = (t_delimiter){">"};
	delimiter[8] = (t_delimiter){"<"};
	delimiter[9] = (t_delimiter){"="};
	delimiter[10] = (t_delimiter){"("};
	delimiter[11] = (t_delimiter){")"};
	delimiter[12] = (t_delimiter){"["};
	delimiter[13] = (t_delimiter){"]"};
	delimiter[14] = (t_delimiter){"{"};
	delimiter[15] = (t_delimiter){"}"};
	delimiter[16] = (t_delimiter){"$"};
	delimiter[17] = (t_delimiter){"."};
	delimiter[18] = (t_delimiter){NULL};
}