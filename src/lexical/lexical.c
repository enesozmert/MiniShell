#include "../../include/header.h"

void lexical_analizer(t_rdl *rdl)
{
	keyword_list(rdl->keyword_list);
	operator_list(rdl->operator_list);
	command_list(rdl->command_list);
	parser(rdl);
}