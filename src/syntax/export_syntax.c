#include "../../include/header.h"

int export_syntax(t_rdl *rdl)
{
	if (ft_strncmp(rdl->token->context, "export",
				   rdl->token->len) == 0)
		return (0);
	if (ft_strncmp(rdl->token->type, "invalid_identifier",
				   ft_strlen(rdl->token->type)) == 0)
	{
		rdl->error_arg = ft_strdup(rdl->main_str);
		return (104);
	}
	return (0);
}