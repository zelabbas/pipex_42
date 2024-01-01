/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:49:01 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/31 10:03:01 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	child2_process(char **argv, int *fd, char **envp)
{
	int	file_ouput;

	close(fd[1]);
	file_ouput = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_ouput == -1)
		ft_error("\033[1;31m🛑ERROR : in step open file !\n\033[0m", 't');
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(file_ouput, STDOUT_FILENO);
	close(file_ouput);
	execute_cmd(argv[3], envp);
}

void	child_process(char **argv, int *fd, char **envp)
{
	int	file_input;

	close(fd[0]);
	file_input = open(argv[1], O_RDONLY);
	if (file_input == -1)
		ft_error("\033[1;31m🛑ERROR: in step open file!\n\033[0m", 't');
	dup2(file_input, STDIN_FILENO);
	close(file_input);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execute_cmd(argv[2], envp);
}

void	split_task(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (pipe(fd) == -1)
		ft_error("\e[1;31m🛑ERROR: FIALD CREATION PIPE!\n", 't');
	pid = fork();
	if (pid == -1)
		ft_error("\e[1;31m🛑ERROR: FIALD CREATION CHILD PROCESS!\n", 't');
	else if (pid == 0)
		child_process(argv, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("\e[1;31m🛑ERROR: FIALD CREATION !\n", 't');
	else if (pid2 == 0)
		child2_process(argv, fd, envp);
	if (pid != 0 && pid2 != 0)
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	check_env(envp);
	if (argc == 5)
	{
		split_task(argv, envp);
	}
	else
	{
		ft_error("\033[1;31m🛑ERROR USAGE :\033[0m", 0);
		ft_error("./pipex infile cmd1 cmd2 outfile\n", 't');
	}
	return (0);
}
