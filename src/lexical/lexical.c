#include "../../include/header.h"

void lexical_analizer(t_rdl *rdl)
{
	command_list(rdl->command_list);
	operator_list(rdl->operator_list);
	parser(rdl);
}