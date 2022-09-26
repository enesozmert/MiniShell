#include "../../include/header.h"

t_rdl *rdl_init(t_rdl *rdl)
{
	if (rdl == NULL)
		rdl = malloc(sizeof(t_rdl) * 1);
	rdl->main_str = ft_read_line();
	rdl->len = ft_strlen(rdl->main_str);
	rdl->buffer = malloc(sizeof(char) * rdl->len);
	rdl->keyword_list = malloc(sizeof(t_keyword) * rdl->len);
	rdl->operator_list = malloc(sizeof(t_operator) * 8);
	rdl->command_list = malloc(sizeof(t_command) * 8);
	rdl->quote = malloc(sizeof(t_quote) * 1);
	rdl->quote->dq = 0;
	rdl->quote->sq = 0;
	rdl->quote->flag = 0;
	rdl->redir = malloc(sizeof(t_redir) * 1);
	rdl->redir->input_count = 0;
	rdl->redir->output_count = 0;
	return (rdl);
}

void rdl_clear(t_rdl *rdl)
{
	free(rdl->keyword_list);
	free(rdl->operator_list);
	free(rdl->main_str);
	free(rdl->buffer);
	free(rdl->token);
	free(rdl->quote);
	// free(rdl->error_arg);
	// if (rdl != NULL)
	// 	free(rdl);
}
