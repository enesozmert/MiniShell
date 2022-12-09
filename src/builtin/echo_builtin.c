#include "../../include/header.h"
static int echo_dollar(t_command command)
{
	if (command.tokens->next->type_id != 10)
		ft_putstr_fd(command.tokens->context, command.file_fd);
		// printf("%s", command.tokens->context);
	return (0);
}

static int echo_key(t_command command)
{
	char *env_value;

	env_value = env_find_value(command.tokens->context);
	if (env_value != NULL)
		ft_putstr_fd(env_value, command.file_fd);
		// printf("%s", env_value);
	return (0);
}

static int echo_string(t_command command)
{
	// printf("%s", command.tokens->context);
	ft_putstr_fd(command.tokens->context, command.file_fd);
	return (0);
}

int echo_start(t_command *command)
{
	int i;
	int size;

	i = -1;
	size = token_size(command->tokens);
	while (++i < size)
	{
		if (command->tokens->type_id == 3)
			echo_dollar(*command);
		if (command->tokens->type_id == 10)
			echo_key(*command);
		if (command->tokens->type_id == 12)
			echo_string(*command);
		get_next_token(&command->tokens);
	}
	ft_putstr_fd("\n", command->file_fd);
	return (0);
}

// key
// value
// end
// exception
// re