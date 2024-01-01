/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:58:43 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/30 15:24:51 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	ft_putstr(const char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_error(const char *str, char c)
{
	if (c == 't')
	{
		ft_putstr(str);
		exit(1);
	}
	else
		ft_putstr(str);
}

void	help_get(char **envp, char ***paths)
{
	int	i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	(*paths) = ft_split(envp[i] + 5, ':');
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	help_get(envp, &paths);
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		if (!path)
		{
			if (part_path)
				free(part_path);
			ft_free_memory(paths);
			ft_error("\033[1;31m🛑ERROR : in step join path !\n\033[0m", 't');
		}
		if (access(path, F_OK) == 0)
			return (ft_free_memory(paths), path);
		free(path);
		free(part_path);
		i++;
	}
	return (ft_free_memory(paths), NULL);
}

void	execute_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (cmd)
	{
		if (*cmd[0] != '/')
			path = get_path(cmd[0], envp);
		else
			path = cmd[0];
		if (!path)
		{
			ft_free_memory(cmd);
			ft_error("\033[1;31m🛑ERROR: in step find path\033[0m", 0);
			ft_error("\033[1;31m (command not found)!\n\033[0m", 't');
		}
		if (execve(path, cmd, envp) == -1)
			ft_free_more(path, cmd);
	}
	else
		ft_error("\033[1;31m🛑ERROR: in split cmd!\n\033[0m", 't');
}
