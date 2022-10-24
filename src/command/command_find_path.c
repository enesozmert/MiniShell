#include "../../include/header.h"

char *command_find_path(t_rdl *rdl)
{
	int i;
    char    *path;
    char	**paths;
	char	*new_path;
	struct	stat	s;
    t_token *token_zero;
	
	i = -1;
    path = env_find_value("PATH");
    paths = ft_split(path, ':');
	token_zero = get_token_id(rdl->token, 0);
    while (paths[++i])
    {
        path = ft_strjoin("/", token_zero->context);
        new_path = ft_strjoin(paths[i], path);
        free(path);
        if (stat(new_path, &s) == 0)
            return (new_path);
        free(new_path);
    }
    return (ft_strdup(token_zero->context));
}
