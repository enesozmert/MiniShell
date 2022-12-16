/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:56:23 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/16 10:27:37 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

void	keyword_list(t_keyword *keyword)
{
	keyword[0] = (t_keyword){"echo", NULL};
	keyword[1] = (t_keyword){"cd", NULL};
	keyword[2] = (t_keyword){"pwd", NULL};
	keyword[3] = (t_keyword){"export", "1"};
	keyword[4] = (t_keyword){"unset", NULL};
	keyword[5] = (t_keyword){"env", NULL};
	keyword[6] = (t_keyword){"exit", NULL};
	keyword[7] = (t_keyword){NULL, NULL};
}
