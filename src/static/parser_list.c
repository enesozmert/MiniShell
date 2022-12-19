/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:26:59 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 10:27:00 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	parser_list(t_parser *parser)
{
	parser[0] = (t_parser){parser_arg_iskeyword_q};
	parser[1] = (t_parser){parser_arg_quote_q};
	parser[2] = (t_parser){parser_arg_isnot_q};
	parser[3] = (t_parser){parser_arg_redir_q};
	parser[4] = (t_parser){parser_arg_pipe_q};
	parser[5] = (t_parser){parser_arg_space_q};
	parser[6] = (t_parser){parser_add_dollar_q};
	parser[7] = (t_parser){parser_add_operator_q};
	parser[8] = (t_parser){parser_add_option_q};
	parser[9] = (t_parser){parser_add_char_q};
	parser[10] = (t_parser){NULL};
}
