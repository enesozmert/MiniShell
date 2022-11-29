#include "../../include/header.h"

int pipe_syntax(t_rdl *rdl)
{
    if (rdl->token->id == 0)
        return (0);
    if (rdl->pipe_prop->count > 2)
        return (105);
    return (0);
}