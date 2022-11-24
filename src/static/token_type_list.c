#include "../../include/header.h"

void	token_type_list(t_token_type *token_type)
{
	token_type[0] = (t_token_type){"keyword", token_type_is_keyword};
	token_type[1] = (t_token_type){"single_quote", token_type_is_single_quote};
	token_type[2] = (t_token_type){"double_quote", token_type_is_double_quote};
	token_type[3] = (t_token_type){"dollar", token_type_is_dollar};
	token_type[4] = (t_token_type){"operator", token_type_is_operator};
	token_type[5] = (t_token_type){"redir", token_type_is_redir};
	token_type[6] = (t_token_type){"valid_identifier", token_type_is_valid_identifier};
	token_type[7] = (t_token_type){"invalid_identifier", token_type_is_invalid_identifier};
	token_type[8] = (t_token_type){"key", token_type_is_key};
	token_type[9] = (t_token_type){"value", token_type_is_value};
	token_type[10] = (t_token_type){"string", token_type_is_string};
	token_type[11] = (t_token_type){"arg", token_type_is_arg};
	token_type[12] = (t_token_type){NULL, NULL};
}