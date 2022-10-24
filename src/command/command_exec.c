#include "../../include/header.h"

int command_execv(t_rdl *rdl)
{
    t_token *token_zero;
    int     result;
    char    *path;

    path = command_find_path(token_zero->context);
	result = execve(path, &token_zero->context, g_env.env);
    if (result == -1)
        return(-1);
    return (0);
}
