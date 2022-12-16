/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:58:40 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/16 03:23:24 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

char	*redir_file_name(t_command *command)
{
    int		i;
	int		j;
	int		len;
	int 	offset;
    char	*file_name;
	char	**tmp;

    i = -1;
	j = 0;
	offset = 0;
	len = 0;
    file_name = NULL;
	tmp = malloc(sizeof(char *) * 3);
    while (++i < command->token_size)
    {
        if (command->tokens->type_id == 12)
		{
			tmp[j++] = ft_strdup(command->tokens->context);
			len += ft_strlen(command->tokens->context);
		}
        get_next_token(&command->tokens);
    }
	tmp[j] = NULL;
	printf("len %d\n", len);
	file_name = malloc(sizeof(char) * len + 1);
	j = -1; 
	while (tmp[++j])
	{
		strcpy(file_name + offset, tmp[j]);
    	offset += ft_strlen(tmp[j]);
	}
	ft_free_dbl_str(tmp);
	file_name[len] = '\0';
    return (file_name);
}