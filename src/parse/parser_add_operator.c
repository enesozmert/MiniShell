/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:12:56 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 13:14:42 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	parser_add_operator(t_rdl *rdl, char c)
{
	t_token		*token;
	t_operator	operator;

	token = malloc(sizeof(t_token));
	operator = find_operator(rdl->operator_list, c);
	token->context = ft_strdup(operator.sybl);
	token->t_flag = 4;
	rdl->token = token_add(rdl->token, token);
	token_delone(token);
}

void	parser_add_dollar(t_rdl *rdl, char c)
{
	t_token	*token;
	char	dollar[2];

	dollar[0] = c;
	dollar[1] = '\0';
	token = malloc(sizeof(t_token));
	token->context = ft_strdup(dollar);
	token->t_flag = 3;
	if (is_dollar(c))
		rdl->token = token_add(rdl->token, token);
	token_delone(token);
}

void	parser_add_redir(t_rdl *rdl, char *buffer)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	token->context = ft_strdup(buffer);
	token->t_flag = 5;
	rdl->token = token_add(rdl->token, token);
	ft_bzero(buffer, ft_strlen(buffer));
	token_delone(token);
}

void	parser_add_option(t_rdl *rdl, char c)
{
	char	option[2];
	t_token	*token;

	option[0] = c;
	option[1] = '\0';
	token = malloc(sizeof(t_token));
	token->context = ft_strdup(option);
	token->t_flag = 7;
	if (is_option(option[0]))
		rdl->token = token_add(rdl->token, token);
	token_delone(token);
}

void	parser_add_pipe(t_rdl *rdl, char c)
{
	char	pipe[2];
	t_token	*token;

	pipe[0] = c;
	pipe[1] = '\0';
	token = malloc(sizeof(t_token));
	token->context = ft_strdup(pipe);
	token->t_flag = 6;
	if (is_pipe(token->context[0]))
		rdl->token = token_add(rdl->token, token);
	token_delone(token);
}
