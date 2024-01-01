/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:37:42 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/01 15:25:50 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		ft_error("\033[1;31m🛑ERROR: in step open file!\n\033[0m", 't');
	return (file);
}

void	write_in_pipe(int *fd, char *line, char *limiter)
{
	close(fd[0]);
	while (line)
	{
		line = get_next_line(0);
		if (!line)
			ft_error("\033[1;31m🛑ERROR: in step get_next_line!\n\033[0m", 't');
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			exit(0);
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = "";
	}
}

void	help_function_here_doc(int *fd, char *limiter, char *line)
{
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error("\033[1;31m🛑ERROR: FAILD CREATION PIPE!\n\033[0m", 't');
	pid = fork();
	if (pid == -1)
		ft_error("\033[1;31m🛑ERROR: FAILD CREATION CHILD\n\033[0m", 't');
	else if (pid == 0)
	{
		write_in_pipe(fd, line, limiter);
	}
	else
	{
		close(fd[1]);
		waitpid(pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}
