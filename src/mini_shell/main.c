/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:19:11 by cyalniz           #+#    #+#             */
/*   Updated: 2022/12/19 12:19:46 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int	main(int argc, char const *argv[], char **env)
{
	env_init(env);
	g_env.exit_status = 0;
	routine();
	return (0);
}
