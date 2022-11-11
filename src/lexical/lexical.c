#include "../../include/header.h"

void lexical_analizer(t_rdl *rdl)
{
	
	keyword_list(rdl->keyword_list);
	operator_list(rdl->operator_list);
	quote_list(rdl->quote_list);
	command_list(rdl->command_list);
	delimiter_list(rdl->delimiter_list);
	identifier_list(rdl->identifier_list);
	token_type_list(rdl->token_type_list);
	parser(rdl);
}