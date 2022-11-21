#include "../../include/header.h"

static int echo_key(t_command command)
{
	char *env_value;

	env_value = env_find_value(command.tokens->context);
	if (env_value != NULL)
		printf("%s", env_value);
	// if (!env_value)
	// 	free(env_value);
	return (0);
}

static int echo_string(t_command command)
{
/* 	if (command.tokens->id != 1 && ft_strncmp(command.tokens->context, "-n", 2) != 0) */
		printf("%s", command.tokens->context);
	return (0);
}

int echo_start(t_command command)
{
	int i;
	int size;
/* 	int	n_flag;
 */
	i = -1;
/* 	n_flag = 0; */
	size = token_size(command.tokens);
	while (++i < size)
	{
		if (command.tokens->type_id == 6)
			echo_key(command);
		if (command.tokens->type_id == 8)
		{
/* 			if (command.tokens->id == 0 && ft_strncmp(command.tokens->context, "-n", 2) == 0)
				n_flag = 1; */
			echo_string(command);
		}
		get_next_token(&command.tokens);
	}
/* 	if (n_flag == 0) */
		printf("\n");
	return (0);
}

// key
// value
// end
// exception
// re