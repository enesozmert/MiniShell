/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:38 by eozmert           #+#    #+#             */
/*   Updated: 2022/08/12 11:08:57 by eozmert          ###   ########.fr       */
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
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"

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
	char			*context;
	struct s_token	*next;
}	t_token;

typedef struct s_word
{
	int				len;
	char			*str;
}	t_word;

typedef struct s_command
{
	char				*type;
	char				*arg;
} t_command;

typedef struct s_rdl
{
	int		len;
	int		word_count;
	char 	*main_str;
	t_command *command_list;
	t_command command;
	t_word	*word;
}	t_rdl;

//main
void			routine();
//lexcical
t_token			*lexical_add(t_token *lst, char **ptr);
void			lexical_append(t_token **lst, t_token *new);
t_token			*lexical_last(t_token *lst);
t_token			*lexical_new(char *context);
void			get_next_token(t_token **token);
int				print_lexical(t_token *token);
void			lexical_lstdelone(t_token *lst);
void			lexical_clear(t_token **token);
//rd_line
char			*ft_read_line(void);
t_rdl			*rdl_init(char *str);
void			rdl_clear(t_rdl *rdl);
t_word			*get_rdl_id(t_rdl *rdl, t_token *token);
//white_space
int				check_white_space(char *input);
//history
int				my_add_history(char *str);
//parser
void			parser(t_token **token, t_rdl *rdl);
t_rdl			*parser_analizer(t_token *token, t_rdl *rdl);
//commands
void			command_list(t_command *commands);
int				commands_clear(t_command *commands);
#endif
