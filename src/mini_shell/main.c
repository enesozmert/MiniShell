/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:19:11 by cyalniz           #+#    #+#             */
/*   Updated: 2023/04/18 00:09:18 by efyaz            ###   ########.fr       */
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
 