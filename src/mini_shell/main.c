#include "../../include/header.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

	pid_t pid;

	if (pid < 0)
		exit(-1);
	if (pid == 0)
		routine();
		
	return 0;
}
