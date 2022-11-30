/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:58:44 by cyalniz           #+#    #+#             */
/*   Updated: 2022/11/30 17:11:51 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int keyword_quoute_syntax(t_rdl *rdl)
{
	int i;
	int d_q;
	int s_q;
	t_token *token;

	d_q = 0;
	s_q = 0;
	i = -1;
	if (rdl->token->id != 0)
		return (0);
	token = get_token_id(rdl->token, 0);
	while(++i < (int)ft_strlen(token->context))
	{
	    if(token->context[i] == '\"' )
	    {
	        d_q++;
	        i++;
	        while(token->context[i] != '\"' && token->context[i] != '\0')
				i++;
	        if(token->context[i] == '\"')
	            d_q++;
	    }
	    else if(token->context[i] == '\'')
	    {
	        s_q++;
	        i++;
	        while(token->context[i] != '\'' && token->context[i] != '\0')
				i++;
	        if(token->context[i] == '\'')
	            s_q++;
	    }
	}
	if (d_q % 2 != 0 || s_q % 2 != 0)
		return(100);
	return (0);
}

int	quote_syntax(t_rdl *rdl)
{
	if (rdl->token->len == 1 && rdl->token->id != 0)
	{
		if (ft_strncmp(rdl->token->type, "single_quote",
				ft_strlen(rdl->token->type)) == 0)
			rdl->quote_prop->sq++;
		else if (ft_strncmp(rdl->token->type, "double_quote",
				ft_strlen(rdl->token->type)) == 0)
			rdl->quote_prop->dq++;
	}
	if ((rdl->quote_prop->sq % 2 != 0 || rdl->quote_prop->dq % 2 != 0)
		&& rdl->token->id == token_size(rdl->token) - 1)
		return (102);
	return (0);
}
