#include "../../include/header.h"

char *env_path(char *env, char *cmd)
{
	int		idx;
	int		counter;
	char	*path;
	char	*path_cmd;
	int		path_cmd_idx;
		
	path_cmd_idx = 0;
	idx = 0;

	while(path[idx])
	{
		if(ft_strnstr(path[idx], cmd, ft_strlen(path[idx])))
			path_cmd_idx++;
		idx++;
	}
}