/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:38 by eozmert           #+#    #+#             */
/*   Updated: 2022/09/27 09:46:36 by cyalniz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_token
{
	int				id;
	int				len;
	char			*type;
	char			*context;
	struct s_token	*next;
}	t_token;

typedef struct	s_quote
{
	int	flag;
	int	dq;
	int	sq;
}	t_quote;

typedef	struct s_redir
{
	int	input_count;
	int	output_count;
}	t_redir;


typedef struct s_rdl
{
	int						len;
	int						word_count;
	int						pipe_count;//new
	char					*main_str;
	char					*buffer;
	char					*error_arg;
	t_quote					*quote;
	t_redir					*redir;
	t_token					*token;
	struct s_keyword		*keyword_list;
	struct s_operator		*operator_list;
	struct s_command		*command_list;
}	t_rdl;

typedef struct s_keyword
{
	char				*type;
}	t_keyword;

typedef struct s_operator
{
	char	*name;
	char	*sybl;
}	t_operator;

typedef struct s_exception
{
	int				error_code;
	char			*message;
	int				(*f)(t_rdl *);
}	t_exception;

typedef struct s_command
{
	char	*type;
	char	**arg;
	char	*option;
	int		(*f)(struct s_command);
	int		count;
}	t_command;


//main
void			routine();
//lexcical
t_token			*token_add(t_token *token, char *ptr);
void			token_append(t_token **token, t_token *new);
t_token			*token_last(t_token *token);
t_token			*token_new(char *context);
int				print_token(t_token *token);
void			token_delone(t_token *token);
void			token_clear(t_token **token);
int				token_size(t_token *token);
void			token_add_index(t_token **token);
void			token_add_type(t_token **token);
t_token			*get_token_id(t_token *token, int id);
void			get_next_token(t_token **token);
//rd_line
char			*ft_read_line(void);
t_rdl			*rdl_init(t_rdl *rdl);
void			rdl_clear(t_rdl *rdl);
//core
int				check_white_space(char *input);
int				count_char(char *str, char c);
int				ft_isalnum(int c);
int				quote_count_left(char *str);
int				quote_count_right(char *str);
int				quote_count(char *str, int c);
int				count_matris(void **matris);
char			*char_replace(char *str, char find, char replace);
int				char_pos(char *str);
char			*keyword_trim(char *str);
int				keyword_trim_len(char *str);
int				token_arg_count(t_token *token);
//history
int				my_add_history(char *str);
//parser
void			parser(t_rdl *rdl);
void			parser_add(t_rdl *rdl, char *buffer);
void			parser_add_operator(t_rdl *rdl, char c);
void			parser_default(t_rdl *rdl);
void			parser_add_buffer(int *j, t_rdl *rdl);
void			parser_arg(t_rdl *rdl);
void			parser_arg_isnotoperator(int *k, t_rdl *rdl);
void			parser_arg_isoperator(int c, int *k, t_rdl *rdl);
void			parser_arg_quote(int c, int *k, t_rdl *rdl);
void			parser_arg_keyword(t_rdl *rdl);
//keywords
void			keyword_list(t_keyword *keyword);
int				keywords_clear(t_keyword *keyword);
int				keywords_size(t_keyword *keyword);
//syntax
void			syntax(t_rdl *rdl);
int				syntax_analizer(t_rdl *rdl);
int				keyword_syntax(t_rdl *rdl);
int				keyword_quoute_syntax(t_rdl *rdl);
int				quote_syntax(t_rdl *rdl);
void			operator_list(t_operator *operator);
int				redir_syntax(t_rdl *rdl);
//quoet
int				single_quote(t_rdl *rdl);
//lexical
void			lexical_analizer(t_rdl *rdl);
int				is_keyword(t_rdl *rdl, char *str);
int				is_operator(t_rdl *rdl, char c);
t_keyword		find_keyword(t_rdl *rdl, char *str);
t_operator		find_operator(t_rdl *rdl, char c);
//exception
int				exception_handler(t_rdl *rdl);
void			exception_write(t_rdl *rdl, char *message);
//command
int				command(t_rdl *rdl);
int				command_create(t_rdl *rdl);
void			command_list(t_command *command);
int				command_run(t_rdl *rdl);
int				command_find(t_rdl *rdl, char *type);
int				command_malloc(t_rdl *rdl);
//builtin
int				echo_start(t_command command);

//new
void			find_pipe_count(t_rdl *rdl);//new
#endif
