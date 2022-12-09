#include "../../include/header.h"

int unset_start(t_command *command)
{
    int i;
	int size;

	i = -1;
	size = token_size(command->tokens);
	while (++i < size)
	{
		if (command->tokens->type_id == 10)
			env_delete(command->tokens->context);
		get_next_token(&command->tokens);
	}
    return (0);
}