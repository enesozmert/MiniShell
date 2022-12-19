/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:58:40 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/19 12:58:31 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char	*redir_file_name(t_command *command)
{
	int		i;
	char	*file_name;
	char	*result;

	i = -1;
	file_name = malloc(sizeof(char));
	result = NULL;
	while (++i < command->token_size)
	{
		if (command->tokens->type_id == 12)
		{
			result = ft_strjoin(file_name, command->tokens->context);
			free(file_name);
			file_name = ft_strdup(result);
			free(result);
		}
		get_next_token(&command->tokens);
	}
	return (file_name);
}
