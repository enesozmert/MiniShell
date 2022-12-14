/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg_query.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:10:12 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/14 16:47:55 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int parser_arg_iskeyword_q(t_rdl *rdl)
{
    if (rdl->key_flag == 1)
    {
        parser_arg_iskeyword(&rdl->i, rdl);
        rdl->i--;
        rdl->key_flag = 0;
        return (1);
    }
    return (0);
}

int parser_arg_quote_q(t_rdl *rdl)
{
    if (is_quote(rdl->quote_list, rdl->main_str[rdl->i]))
    {
        parser_arg_quote(&rdl->i, rdl);
        return (1);
    }
    return (0);
}

int parser_arg_isnot_q(t_rdl *rdl)
{
    if (ft_isalnum(rdl->main_str[rdl->i]))
    {
        parser_arg_isnot(&rdl->i, rdl);
        return (1);
    }
    return (0);
}

int parser_arg_redir_q(t_rdl *rdl)
{
    if ((rdl->main_str[rdl->i] == '>') || (rdl->main_str[rdl->i] == '<'))
    {
        parser_arg_redir(&rdl->i, rdl);
        return (1);
    }
    return (0);
}

int parser_arg_pipe_q(t_rdl *rdl)
{
    if (is_pipe(rdl->main_str[rdl->i]) && is_pipe(rdl->main_str[rdl->i + 1]) == 0)
    {
        parser_arg_pipe(&rdl->i, rdl);
        rdl->key_flag = 1;
        return (1);
    }
    return (0);
}

int parser_arg_space_q(t_rdl *rdl)
{
    if (rdl->main_str[rdl->i] <= 32)
    {
        if (is_next_redir(rdl->i, rdl->main_str) == 0 && is_next_pipe(rdl->i, rdl->main_str) == 0)
            parser_arg_space(&rdl->i, rdl);
        return (1);
    }
    return (0);
}
