#include "../../include/header.h"

void pipe_handler(t_rdl *rdl)
{
    int i;
    int count;
    int nproc;

    i = -1;
    count = rdl->pipe_prop->count;
    nproc = count + 1;
    if (count < 1)
        return;
    while (++i < count + 1)
    {
        if (syntax(rdl) != -1)
            command(rdl);
    }
    while (nproc-- > 0)
        waitpid(-1, 0, 0);
}