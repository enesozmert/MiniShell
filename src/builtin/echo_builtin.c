#include "../../include/header.h"

static int echo_key(t_command command)
{
	char *env_value;

	env_value = env_find_value(command.tokens->context);
	printf("%s", env_value);
	if (!env_value)
		free(env_value);
	return (0);
}

// static int echo_string(t_command command)
// {
// 	printf("%s", command.tokens->context);
// 	printf("\n");
// 	return (0);
// }

int echo_start(t_command command)
{
	int i;

	i = -1;
	// printf("aaa : %d", token_size(command.tokens));
	while (++i < token_size(command.tokens))
	{
		printf("token_type_id: %d , context: %s\n", command.tokens->type_id ,command.tokens->context);
		if (command.tokens->type_id == 6)
			echo_key(command);
		if (command.tokens->type_id == 8)
		{
			printf("%s", command.tokens->context);
			printf("\n");
		}
		get_next_token(&command.tokens);
	}

	// echo_key(command);
	// echo_value(command);
	return (0);
}

// key
// value
// end
// exception
// re