#include "../../include/header.h"

t_rdl *rdl_init(t_rdl *rdl)
{
	if (rdl == NULL)
		rdl = malloc(sizeof(t_rdl) * 1);
	rdl->main_str = ft_read_line();
	rdl->len = ft_strlen(rdl->main_str);
	rdl->index_flag = 0;
	rdl->keywords_id = NULL;
	rdl->buffer = malloc(sizeof(char) * rdl->len);
	rdl->keyword_list = malloc(sizeof(t_keyword) * 8);
	rdl->operator_list = malloc(sizeof(t_operator) * 3);
	rdl->delimiter_list = malloc(sizeof(t_delimiter) * 18);
	rdl->identifier_list = malloc(sizeof(t_operator) * 11);
	rdl->command_list = malloc(sizeof(t_command) * 10);
	rdl->token_type_list = malloc(sizeof(t_token_type) * 15);
	rdl->redir_list = malloc(sizeof(t_redir) * 3);
	rdl->quote_list = malloc(sizeof(t_quote) * 3);
	rdl->quote_prop = malloc(sizeof(t_quote_prop) * 1);
	rdl->quote_prop->dq = 0;
	rdl->quote_prop->sq = 0;
	rdl->quote_prop->flag = 0;
	rdl->token_type_prop = malloc(sizeof(t_token_type_prop) * 1);
	rdl->token_type_prop->opr_flag = 0;
	rdl->token_type_prop->dq_flag = 0;
	rdl->token_type_prop->sq_flag = 0;
	rdl->token_type_prop->dollar_flag = 0;
	rdl->token_type_prop->space_flag = 0;
	rdl->token_type_prop->new_trim = NULL;
	rdl->redir_prop = malloc(sizeof(t_redir_prop) * 1);
	rdl->redir_prop->input_count = 0;
	rdl->redir_prop->output_count = 0;
	rdl->redir_prop->context = ft_strdup("");
	rdl->redir_prop->file_name = ft_strdup("");
	rdl->pipe_prop = malloc(sizeof(t_pipe_prop) * 1);
	rdl->pipe_prop->count = 0;
	rdl->pipe_prop->index = -1;
	return (rdl);
}

void rdl_clear(t_rdl *rdl)
{
	free(rdl->keyword_list);
	free(rdl->command_list);
	free(rdl->operator_list);
	free(rdl->delimiter_list);
	free(rdl->identifier_list);
	free(rdl->token_type_list);
	free(rdl->quote_list);
	free(rdl->main_str);
	free(rdl->buffer);
	free(rdl->token);
	free(rdl->quote_prop);
	free(rdl->token_type_prop);
	// free(rdl->error_arg);
	// if (rdl != NULL)
	// 	free(rdl);
}
