/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:45:23 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 12:11:39 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	token_type_list(t_token_type *token_type)
{
	token_type[0] = (t_token_type){"keyword", token_type_is_keyword};
	token_type[1] = (t_token_type){"single_quote", token_type_is_single_quote};
	token_type[2] = (t_token_type){"double_quote", token_type_is_double_quote};
	token_type[3] = (t_token_type){"dollar", token_type_is_dollar};
	token_type[4] = (t_token_type){"operator", token_type_is_operator};
	token_type[5] = (t_token_type){"redir", token_type_is_redir};
	token_type[6] = (t_token_type){"pipe", token_type_is_pipe};
	token_type[7] = (t_token_type){"option", token_type_is_option};
	token_type[8] = (t_token_type){"valid_identifier",
		token_type_is_valid_identifier};
	token_type[9] = (t_token_type){"invalid_identifier",
		token_type_is_invalid_identifier};
	token_type[10] = (t_token_type){"key", token_type_is_key};
	token_type[11] = (t_token_type){"value", token_type_is_value};
	token_type[12] = (t_token_type){"string", token_type_is_string};
	token_type[13] = (t_token_type){"arg", token_type_is_arg};
	token_type[14] = (t_token_type){"space", token_type_is_space};
	token_type[15] = (t_token_type){NULL, NULL};
}
