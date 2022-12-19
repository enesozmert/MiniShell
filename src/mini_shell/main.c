/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:19:11 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 12:48:28 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	main(int argc, char const *argv[], char **env)
{
	(void)argc;
	(void)argv;
	env_init(env);
	g_env.exit_status = 0;
	routine();
	return (0);
}
