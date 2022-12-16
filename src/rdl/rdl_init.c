/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:36:59 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/16 13:52:54 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static void rdl_init_list(t_rdl *rdl)
{
	rdl->parser_list = malloc(sizeof(t_parser) * 11);
	rdl->keyword_list = malloc(sizeof(t_keyword) * 8);
	rdl->operator_list = malloc(sizeof(t_operator) * 3);
	rdl->delimiter_list = malloc(sizeof(t_delimiter) * 18);
	rdl->identifier_list = malloc(sizeof(t_operator) * 11);
	rdl->command_list = malloc(sizeof(t_command) * 11);
	rdl->token_type_list = malloc(sizeof(t_token_type) * 16);
	rdl->redir_list = malloc(sizeof(t_redir) * 5);
	rdl->quote_list = malloc(sizeof(t_quote) * 3);
	rdl->quote_prop = malloc(sizeof(t_quote_prop) * 1);
}
static void rdl_init_quote_prop(t_rdl *rdl)
{
	rdl->quote_prop->dq = 0;
	rdl->quote_prop->sq = 0;
	rdl->quote_prop->flag = 0;
}

static void rdl_init_token_type_prop(t_rdl *rdl)
{
	rdl->token_type_prop = malloc(sizeof(t_token_type_prop) * 1);
	rdl->token_type_prop->opr_flag = 0;
	rdl->token_type_prop->dq_flag = 0;
	rdl->token_type_prop->sq_flag = 0;
	rdl->token_type_prop->dollar_flag = 0;
	rdl->token_type_prop->redir_flag = 0;
	rdl->token_type_prop->space_flag = 0;
	rdl->token_type_prop->redir_flag = 0;
	rdl->token_type_prop->new_trim = NULL;
}

static void rdl_init_redir_pipe_prop(t_rdl *rdl)
{
	rdl->redir_prop = malloc(sizeof(t_redir_prop) * 1);
	rdl->redir_prop->input_count = 0;
	rdl->redir_prop->output_count = 0;
	rdl->redir_prop->count = 0;
	rdl->redir_prop->index = -1;
	rdl->pipe_prop = malloc(sizeof(t_pipe_prop) * 1);
	rdl->pipe_prop->count = 0;
	rdl->pipe_prop->index = -1;
}

t_rdl *rdl_init(t_rdl *rdl)
{
	if (rdl == NULL)
		rdl = malloc(sizeof(t_rdl) * 1);
	rdl->main_str = ft_read_line();
	rdl->len = ft_strlen(rdl->main_str);
	rdl->i = 0;
	rdl->key_flag = 0;
	rdl->keywords_id = NULL;
	rdl->none = ft_strdup("none");
	rdl->buffer = malloc(sizeof(char) * rdl->len);
	rdl->token_type_pre_id = -1;
	rdl_init_list(rdl);
	// rdl->command_list[7].keyword = ft_strdup(rdl->none);
	// printf("command 7 : %p\n",rdl->command_list[7].keyword);
	// rdl->command_list[8].keyword = ft_strdup(rdl->none);
	// rdl->command_list[9].keyword = ft_strdup(rdl->none);
	rdl_init_quote_prop(rdl);
	rdl_init_token_type_prop(rdl);
	rdl_init_redir_pipe_prop(rdl);
	return (rdl);
}