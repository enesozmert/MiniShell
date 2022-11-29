#include "../../include/header.h"

void ft_closepipes(int fd[2])
{
	close(fd[READ]);
	close(fd[WRITE]);
}