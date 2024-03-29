/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efyaz <efyaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:29:03 by eozmert           #+#    #+#             */
/*   Updated: 2023/04/18 00:08:00 by efyaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>
# include "../libft/libft.h"

# define READ 0
# define WRITE 1

typedef struct s_token
{
	int				id;
	int				len;
	int				type_id;
	char			*context;
	int				t_flag;
	int				keyword_id;
	struct s_token	*next;
}	t_token;

typedef struct s_quote_prop
{
	int	flag;
	int	dq;
	int	sq;
	int	k_sq;
	int	k_dq;
}	t_quote_prop;

typedef struct s_quote
{
	char	*name;
	char	*sybl;
}	t_quote;

typedef struct s_pipe_prop
{
	int	count;
	int	syntax_count;
	int	index;
}	t_pipe_prop;

typedef struct s_redir_prop
{
	int	input_count;
	int	output_count;
	int	count;
	int	index;
}	t_redir_prop;

typedef struct s_redir
{
	char	*sybl;
}	t_redir;

typedef struct s_token_type_prop
{
	int				opr_f;
	int				sq_f;
	int				dq_f;
	int				space_f;
	int				dollar_f;
	int				redir_f;
	int				option_f;
	int				keyword_id;
	char			*trim;
	struct s_token	*token;
}	t_token_type_prop;

typedef struct s_rdl
{
	int					i;
	int					len;
	int					word_count;
	int					t_flag;
	int					key_flag;
	char				*none;
	char				*main_str;
	int					*keywords_id;
	char				*buffer;
	char				*error_arg;
	t_quote_prop		*quote_prop;
	t_token_type_prop	*ttp;
	int					token_type_pre_id;
	t_redir_prop		*redir_prop;
	t_pipe_prop			*pipe_prop;
	t_token				*token;
	struct s_parser		*parser_list;
	struct s_redir		*redir_list;
	struct s_keyword	*keyword_list;
	struct s_operator	*operator_list;
	struct s_delimiter	*delimiter_list;
	struct s_identifier	*identifier_list;
	struct s_command	*command_list;
	struct s_token_type	*token_type_list;
	struct s_quote		*quote_list;
}	t_rdl;

typedef struct s_parser
{
	int	(*f)(struct s_rdl *);
}	t_parser;

typedef struct s_keyword
{
	char	*type;
	char	*operators_id;
}	t_keyword;

typedef struct s_operator
{
	char	*name;
	char	*sybl;
}	t_operator;

typedef struct s_delimiter
{
	char	*sybl;
}	t_delimiter;

typedef struct s_identifier
{
	char	*sybl;
}	t_identifier;

typedef struct s_token_type
{
	char	*name;
	int		(*f)(t_rdl *);
}	t_token_type;

typedef struct s_exception
{
	int				error_code;
	char			*exit_status;
	char			*message;
	int				(*f)(t_rdl *);
}	t_exception;

typedef struct s_command
{
	char	*name;
	char	*keyword;
	char	*token_types_id;
	t_token	*tokens;
	int		(*f)(struct s_command *);
	int		count;
	int		pipe_count;
	int		redir_count;
	int		token_size;
	int		token_sub_type_id;
	int		token_type_pre_id;
	int		tmp_fd;
	int		file_fd;
}	t_command;

typedef struct s_env
{
	char	**env;
	int		exit_status;
}	t_env;

t_env			g_env;
extern t_env	g_env;

void		routine(void);
t_token		*token_add(t_token *token, t_token *token_cpy);
void		token_append(t_token **token, t_token *new);
t_token		*token_last(t_token *token);
t_token		*token_new(t_token *get_token);
t_token		*token_add_copy(t_token *token, t_token *get_token);
void		token_delone(t_token *token);
void		token_clear(t_token **token);
int			token_size(t_token *token);
void		token_add_index(t_token **token);
void		token_add_type(t_rdl *rdl, t_token **token);
int			token_add_type_handler(t_rdl *rdl);
int			print_token(t_token *token);
t_token		*get_token_id(t_token *token, int id);
t_token		*get_token_type_id(t_token *token, int type_id);
void		get_next_token(t_token **token);
void		get_next_token_rra(t_token **token);
int			is_token_type(t_token_type *token_type_list, char *str);
void		token_type_list(t_token_type *token_type);
int			token_type_is_keyword(t_rdl *rdl);
int			token_type_is_single_quote(t_rdl *rdl);
int			token_type_is_double_quote(t_rdl *rdl);
int			token_type_is_valid_identifier(t_rdl *rdl);
int			token_type_is_invalid_identifier(t_rdl *rdl);
int			token_type_is_value(t_rdl *rdl);
int			token_type_is_key(t_rdl *rdl);
int			token_type_is_operator(t_rdl *rdl);
int			token_type_is_value(t_rdl *rdl);
int			token_type_is_arg(t_rdl *rdl);
int			token_type_is_string(t_rdl *rdl);
int			token_type_is_dollar(t_rdl *rdl);
int			token_type_is_redir(t_rdl *rdl);
int			token_type_is_option(t_rdl *rdl);
int			token_type_is_pipe(t_rdl *rdl);
int			token_type_is_space(t_rdl *rdl);
void		token_add_keyword_id(t_rdl *rdl, t_token **token);
int			token_find_count(t_token *token, char *context);
char		*s1free_join(char *s1, char *s2);
char		*ft_read_line(void);
t_rdl		*rdl_init(t_rdl *rdl);
void		rdl_clear(t_rdl *rdl);
int			check_white_space(char *input);
int			count_char(char *str, char c);
int			ft_isalnum(int c);
int			quote_count_left(char *str);
int			quote_count_right(char *str);
int			quote_count(char *str, int c);
int			count_matris(void **matris);
char		*char_replace(char *str, char find, char replace);
void		char_pos(int *k, t_rdl *rdl);
char		*keyword_trim(char *str);
int			keyword_trim_len(char *str);
int			token_arg_count(t_token *token);
int			token_key_count(t_token *token);
int			token_value_count(t_token *token);
void		ft_free_dbl_str(char **str);
char		*to_lower_str(char *str);
void		token_pre(t_rdl *rdl);
void		space_clear(char *str, int *k);
int			my_add_history(char *str);
void		parser(t_rdl *rdl);
void		parser_add(t_rdl *rdl, char *buffer);
void		parser_add_operator(t_rdl *rdl, char c);
void		parser_add_redir(t_rdl *rdl, char *buffer);
void		parser_add_option(t_rdl *rdl, char c);
void		parser_add_pipe(t_rdl *rdl, char c);
void		parser_add_char(t_rdl *rdl, char c);
void		parser_add_space(t_rdl *rdl, char *buffer);
void		parser_add_quote(t_rdl *rdl, char c);
void		parser_add_dollar(t_rdl *rdl, char c);
void		parser_add_buffer(t_rdl *rdl, char *buffer, int *k);
void		parser_add_keyword(t_rdl *rdl, char *buffer);
void		parser_create(t_rdl *rdl);
void		parser_arg_is_quote(int c, int *k, t_rdl *rdl);
void		parser_arg_isnot(int *k, t_rdl *rdl);
void		parser_arg_is(t_rdl *rdl);
void		parser_arg_isoperator(int *k, t_rdl *rdl);
void		parser_arg_iskeyword(int *k, t_rdl *rdl);
void		parser_arg_quote(int *k, t_rdl *rdl);
void		parser_arg_keyword(int *k, t_rdl *rdl);
void		parser_arg_space(int *k, t_rdl *rdl);
void		parser_arg_pipe(int *k, t_rdl *rdl);
void		parser_arg_redir(int *k, t_rdl *rdl);
int			parser_arg_iskeyword_q(t_rdl *rdl);
int			parser_arg_quote_q(t_rdl *rdl);
int			parser_arg_isnot_q(t_rdl *rdl);
int			parser_arg_redir_q(t_rdl *rdl);
int			parser_arg_pipe_q(t_rdl *rdl);
int			parser_arg_space_q(t_rdl *rdl);
int			parser_add_dollar_q(t_rdl *rdl);
int			parser_add_operator_q(t_rdl *rdl);
int			parser_add_option_q(t_rdl *rdl);
int			parser_add_char_q(t_rdl *rdl);
void		parser_list(t_parser *parser);
void		parser_handler(t_rdl *rdl);
void		keyword_list(t_keyword *keyword);
int			keywords_clear(t_keyword *keyword);
int			keywords_size(t_keyword *keyword);
int			syntax(t_rdl *rdl);
int			syntax_analizer(t_rdl *rdl);
int			keyword_syntax(t_rdl *rdl);
int			keyword_quoute_syntax(t_rdl *rdl);
int			quote_syntax(t_rdl *rdl);
void		operator_list(t_operator *operator);
int			redir_syntax(t_rdl *rdl);
int			pipe_syntax(t_rdl *rdl);
int			export_syntax(t_rdl *rdl);
int			single_quote(t_rdl *rdl);
void		quote_list(t_quote *quote);
void		keywords_id(t_rdl *rdl);
void		lexical_analizer(t_rdl *rdl);
int			is_keyword(t_keyword *keyword_list, char *str);
int			is_keyword_exec(t_keyword *keyword_list, char *str);
int			is_keyword_builtin(t_keyword *keyword_list, char *str);
int			is_operator(t_operator *operator_list, char c);
int			is_quote(t_quote *quote_list, char c);
int			is_dollar(char c);
int			is_option(char c);
int			is_delimiter(t_delimiter *delimiter_list, char c);
int			is_identifier(t_identifier *identifier_list, char *str);
int			is_redir(t_redir *redir_list, char *str);
int			find_redir_id(t_redir *redir_list, char *str);
int			is_next_redir(int k, char *str);
int			is_next_pipe(int k, char *str);
int			is_pipe(char c);
t_keyword	find_keyword(t_keyword *keyword_list, char *str);
int			find_keyword_id(t_keyword *keyword_list, char *str);
t_operator	find_operator(t_operator *operator_list, char c);
t_quote		find_quote(t_quote *quote_list, char c);
int			command_in_token_type(t_rdl *rdl, int command_id, int token_id);
int			keyword_in_operator(t_rdl *rdl, int keyword_id, char operator);
int			exception_handler(t_rdl *rdl);
void		exception_write(t_rdl *rdl, char *message);
int			command(t_rdl *rdl);
int			command_malloc(t_rdl *rdl);
int			command_clear(t_command *command_list);
int			command_create(t_rdl *rdl);
void		command_list(t_command *command);
int			command_run(t_command *command_list);
int			command_exec(t_command *command);
char		*command_find_path(char *keyword);
int			command_find(t_rdl *rdl, int token_id);
int			command_fork(t_command *command);
int			echo_start(t_command *command);
int			cd_start(t_command *command);
int			pwd_start(t_command *command);
int			exit_start(t_command *command);
int			env_start(t_command *command);
int			export_start(t_command *command);
int			unset_start(t_command *command);
void		env_all_update(char **env, int count);
int			env_init(char **env);
int			env_len(char **env);
int			env_exist(char *key);
int			env_find_id(char *key);
char		*env_find_value(char *key);
int			env_add(char *key, char *value);
int			env_update(char *key, char *value);
int			env_delete(char *key);
int			env_asc(char **env);
int			option_count(t_token *token);
void		delimiter_list(t_delimiter *delimiter);
void		identifier_list(t_identifier *identifier);
void		set_signal(int signo);
void		proc_signal_handler(int signo);
void		interrupt_here_document(int signo);
void		redir_list(t_redir *redir);
void		redir_handler(t_rdl *rdl);
int			redir_count(t_rdl *rdl);
int			redir_exec(t_command *command);
char		*redir_file_name(t_command *command);
int			redir_file_create(t_command *command, char *name);
int			redir_out_exec(t_command *command);
int			redir_in_exec(t_command *command);
int			redir_here_out_exec(t_command *command);
int			redir_here_in_exec(t_command *command);
void		pipe_handler(t_rdl *rdl);
int			pipe_count(t_rdl *rdl);
int			pipe_exec(t_command *command);
void		ft_openpipes(t_command command, int fd[2]);
void		ft_closepipes(int fd[2]);
void		ft_openredir(t_command command, int fd[2]);
void		ft_closeredir(int fd[2]);
#endif
