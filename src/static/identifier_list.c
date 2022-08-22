#include "../../include/header.h"

void	identifier_list(t_identifier *identifier)
{
	identifier[0] = (t_identifier){"."};
	identifier[1] = (t_identifier){"/"};
	identifier[2] = (t_identifier){"~"};
	identifier[3] = (t_identifier){","};
	identifier[4] = (t_identifier){"{"};
	identifier[5] = (t_identifier){"}"};
	identifier[6] = (t_identifier){"["};
	identifier[7] = (t_identifier){"]"};
	identifier[8] = (t_identifier){")"};
	identifier[9] = (t_identifier){"("};
	identifier[10] = (t_identifier){"*"};
	identifier[11] = (t_identifier){"%"};
	identifier[12] = (t_identifier){":"};
	identifier[13] = (t_identifier){";"};
	identifier[14] = (t_identifier){"-"};
	identifier[15] = (t_identifier){"-"};
	identifier[16] = (t_identifier){"!"};
	identifier[17] = (t_identifier){"#"};
	identifier[18] = (t_identifier){"+"};
	identifier[19] = (t_identifier){"@"};
	identifier[20] = (t_identifier){"?"};
	identifier[21] = (t_identifier){"="};
	identifier[22] = (t_identifier){NULL};
}