#include "../../include/header.h"

void parser(t_rdl *rdl)
{
	int		i;
	int		j;
	char	c;
	char	*buffer;

	i = -1;
	j = 0;
	c = ' ';
	buffer = malloc(sizeof(char) * 30);
	while (rdl->main_str[++i])
	{
		c = rdl->main_str[i];
		if (is_operator(rdl, c))
			printf("%c is operator\n", c);
		if (ft_isalnum(c) || c == ' ')
		{
			buffer[j++] = c;
		}
		else if ((c != ' ' || c != '\t') && (j != 0))
		{
			buffer[j] = '\0';
			j = 0;

			if (is_keyword(rdl, ft_strtrim(buffer, " ")) == 1)
			{
				printf("%s is keyword\n", buffer);
			}
			else if (is_keyword(rdl, buffer) == 0)
			{
				printf("%s is indentifier\n", buffer);
			}
			ft_bzero(buffer, ft_strlen(buffer));
		}
	}
	print_token(rdl->token);
}

t_rdl *parser_analizer(t_rdl *rdl)
{
	int i;
	int s_i;
	t_token *token_zero;

	i = -1;
	s_i = 0;
	token_zero = get_token_id(rdl->token, 0);
	printf("token zero %s\n", token_zero->context);
	command_list(rdl->command_list);
	while (rdl->command_list[++i].type != NULL)
	{
		if (ft_strncmp(rdl->command_list[i].type, token_zero->context,
					   ft_strlen(rdl->command_list[i].type)) == 0)
		{
			s_i = i;
			break;
		}
	}
	i = 0;
	rdl->command_list[s_i].arg =
		ft_strdup(&rdl->main_str[token_zero->len + 1]);
	rdl->command = rdl->command_list[s_i];
	return (rdl);
}
