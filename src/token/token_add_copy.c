/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 10:13:13 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 10:13:20 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

t_token	*token_add_copy(t_token *token, t_token *get_token)
{
	token_append(&token, token_new(get_token));
	token_add_index(&token);
	return (token);
}
