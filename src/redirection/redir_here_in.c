/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_here_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:04:17 by eozmert           #+#    #+#             */
/*   Updated: 2022/12/16 02:19:25 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

static void	redir_here_in_file_clear(void)
{
	int		tmp_fd;

	tmp_fd = open("here_in.txt", O_WRONLY | O_TRUNC, 0600);
	close(tmp_fd);
}

static void	redir_here_in_file_run(t_command *command)
{
	int		tmp_fd;

	tmp_fd = open("here_in.txt", O_RDONLY);
	unlink("here_in.txt");
	dup2(tmp_fd, command->file_fd);
	close(tmp_fd);
}

static int redir_here_in_file(t_command *command)
{
	int fd_file;
	int jump_token;
	int take_token;

	printf("redir_here_in_file\n");
	fd_file = 0;
	if (command->pipe_count > 0)
	{
		jump_token = command->pipe_count + 1;
		take_token = command->redir_count + command->pipe_count + 1;
	}
	else
	{
		jump_token = 1;
		take_token = command->redir_count + 1;
	}
	if (command->count < take_token && command->count > jump_token)
	{
		printf("file name1 : %s\n", "here_in.txt");
		fd_file = redir_file_create(command, "here_in.txt");
		close(fd_file);
	}
	else if (command->count == take_token && command->count > jump_token)
	{
		printf("file name2 : %s\n", "here_in.txt");
		fd_file = redir_file_create(command, "here_in.txt");
	}
	return (fd_file);
}

static void redir_here_in_input(t_command *command)
{
	printf("redir_here_in_exec\n");
	char *end;
	char *input;

	input = NULL;
	end = redir_file_name(command);
	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			close(command->file_fd);
			exit(0);
		}
		if (ft_strncmp(input, end, ft_strlen(input)))
		{
			ft_putendl_fd(input, command->file_fd);
		}
		else
		{
			free(input);
			break;
		}
		free(input);
	}
	exit(0);
}

int redir_here_in_exec(t_command *command)
{
	pid_t pid;
	int status;
	int fd_file;

	status = 0;
	fd_file = redir_here_in_file(command);
	command->file_fd = fd_file;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		redir_here_in_input(command);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		redir_here_in_file_clear();
	redir_here_in_file_run(command);
	return (fd_file);
}