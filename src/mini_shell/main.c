#include "../../include/header.h"

int main(int argc, char const *argv[], char **env)
{
	(void)argc;
	(void)argv;
	// set_signal();
	env_init(env);
	routine();
	return 0;
}
