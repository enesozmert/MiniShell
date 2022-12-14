#include "../../include/header.h"

int main(int argc, char const *argv[], char **env)
{
	(void)argc;
	(void)argv;

	env_init(env);
	g_env.exit_status = 0;
	routine();
	return 0;
}
