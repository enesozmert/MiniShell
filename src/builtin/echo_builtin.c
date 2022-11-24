#include "../../include/header.h"
static int echo_dollar(t_command command)
{
	if (command.tokens->next->type_id != 8)
		printf("%s", command.tokens->context);
	return (0);
}

static int echo_key(t_command command)
{
	char *env_value;

	env_value = env_find_value(command.tokens->context);
	if (env_value != NULL)
		printf("%s", env_value);
	return (0);
}

static int echo_string(t_command command)
{
	printf("%s", command.tokens->context);
	return (0);
}

int echo_start(t_command command)
{
	int i;
	int size;

	i = -1;
	size = token_size(command.tokens);
	while (++i < size)
	{
		if (command.tokens->type_id == 3)
			echo_dollar(command);
		if (command.tokens->type_id == 8)
			echo_key(command);
		if (command.tokens->type_id == 10)
			echo_string(command);
		get_next_token(&command.tokens);
	}
		printf("\n");
	return (0);
}

// key
// value
// end
// exception
// re