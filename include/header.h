/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:38 by eozmert           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/11 13:35:09 by eozmert          ###   ########.fr       */
=======
/*   Updated: 2022/08/11 13:16:11 by cyalniz          ###   ########.fr       */
>>>>>>> 18027617160437d820ff749443cc905612dd19bd
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
	int				id;
	char			*context;
	struct s_token	*next;
}	t_token;

typedef struct s_word
{
	int				len;
	char			*str;
}	t_word;

typedef struct s_readline_prop
{
	int		len;
	int		word_count;
	char 	*main_str;
	t_word	*word;
}	t_readline_prop;

//lexcical
t_token			*lexical_add(t_token *lst, char **ptr);
void			lexical_append(t_token **lst, t_token *new);
t_token			*lexical_last(t_token *lst);
t_token			*lexical_new(char *context);
void			get_next_token(t_token **token);
int				print_lexical(t_token *token);
void			lexical_lstdelone(t_token *lst);
void			lexical_clear(t_token **token);

t_readline_prop	ft_read_line(void);

int	check_white_space(char *input);

int				my_add_history(char *str);


int				parser(t_token **token, t_readline_prop **rd_prop);
int				parser_analizer(t_token *token);
void			routine();
#endif
