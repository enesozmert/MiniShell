/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:32:33 by cyalniz           #+#    #+#             */
/*   Updated: 2022/10/11 23:12:15 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int cd_home(t_command command)
{
    //command.arg[1] kontrolü yapılacak
    (void)command;
    char *path;
    path = env_find_value("HOME");
    chdir(path);
    return 1;
}

static void		add_export(char *str, char **new, int i)
{
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
}

static int			check_export(char *str)
{
	int		i;
	char	**new;

	if (str[0] == '=' || str[0] == '\0' || ft_strlen(str) == 1)
		return (0);
	i = -1;
	while (g_env.env[++i] != NULL)
		if (!ft_strncmp(g_env.env[i], str, ft_strlen(str)))
		{
			g_env.env[i] = ft_strdup(str);
			return (1);
		}
	if (!(new = malloc(sizeof(char*) * (i + 2))))
		return (0);
	i = -1;
	while (g_env.env[++i])
		new[i] = ft_strdup(g_env.env[i]);
	add_export(str, new, i);
	g_env.env = new;
	return (1);
}

static void		set_oldpwd_pwd()
{
	char	*cur_pwd;
	char	*old_pwd;
	char	*tmp;

	tmp = malloc(sizeof(char) * 1024);
	cur_pwd = ft_strjoin("PWD=", getcwd(tmp, 1024));
	old_pwd = ft_strjoin("OLDPWD=", env_find_value("PWD"));
	check_export(cur_pwd);
	check_export(old_pwd);
	free(cur_pwd);
	free(old_pwd);
}

int cd_start(t_command command)
{
    char *new_dir;
    
    if (command.arg[0] == NULL)
        return(105);
    if (strcmp(command.arg[0], "~") != 0 && strcmp(command.arg[0], "$") != 0)
    {
        new_dir = ft_strdup(command.arg[0]);
        if (chdir(new_dir) == -1)
            return (104);
        else
        {
            getcwd(new_dir, sizeof(new_dir));
            set_oldpwd_pwd();
        }

        free(new_dir);
    }
    if (strcmp(command.arg[0], "~") == 0)
        cd_home(command);
    
    return (0);
}