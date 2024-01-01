/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:05:30 by zelabbas          #+#    #+#             */
/*   Updated: 2024/01/01 15:29:11 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	child_process(char *argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error("\033[1;31m🛑ERROR: FAILD CREATION PIPE!\n\033[0m", 't');
	pid = fork();
	if (pid == -1)
		ft_error("\033[1;31m🛑ERROR: FAILD CREATION CHILD!\n\033[0m", 't');
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute_cmd(argv, envp);
	}
	else
	{
		close(fd[1]);
		waitpid(pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

void	here_doc(char *limiter, int argc)
{
	char	*line;
	int		fd[2];

	line = "";
	if (argc < 6)
	{
		ft_error("\033[1;31m🛑ERROR USAGE:\033[0m", 0);
		ft_error(
			"\033[1;31m ./pipex here_doc LIMITER cmd cmd1 file\n\033[0m", 't');
	}
	help_function_here_doc(fd, limiter, line);
}

void	split_task(int argc, char **argv, char **envp)
{
	int	i;
	int	file_input;
	int	file_output;

	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		i = 3;
		file_output = open_file(argv[argc - 1], 0);
		here_doc(argv[2], argc);
	}
	else
	{
		i = 2;
		file_output = open_file(argv[argc - 1], 1);
		file_input = open_file(argv[1], 2);
		dup2(file_input, 0);
	}
	while (i < argc - 2)
		child_process(argv[i++], envp);
	dup2(file_output, 1);
	close(file_output);
	execute_cmd(argv[argc - 2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	check_env(envp);
	if (argc >= 5)
	{
		split_task(argc, argv, envp);
	}
	ft_error("\033[1;31m🛑ERROR USAGE :\n\033[0m", 't');
}
