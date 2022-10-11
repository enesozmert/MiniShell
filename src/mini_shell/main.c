#include "../../include/header.h"

int main(int argc, char const *argv[], char **env)
{
	(void)argc;
	(void)argv;
	printf("%s\n", env[0]);
	routine();
	return 0;
}
