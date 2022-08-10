/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyalniz <cyalniz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:08:38 by eozmert           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/10 12:37:23 by cyalniz          ###   ########.fr       */
=======
/*   Updated: 2022/08/10 12:36:11 by eozmert          ###   ########.fr       */
>>>>>>> 09ed74f054b4466d8084436911c3d7c001cb7e81
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
	char	*str;
	int		len;
	int		word_count;
}	t_readline_prop;

t_token		*lexical_add(char **ptr);
void		lexical_append(t_token **lst, t_token *new);
t_token		*lexical_last(t_token *lst);
t_token		*lexical_new(char *context);
int			print_lexical(t_token *token);
t_readline_prop ft_read_line(void);
//history
int			my_add_history(char *str);
#endif
