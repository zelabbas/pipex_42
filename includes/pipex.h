/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:56:31 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/31 22:23:37 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "get_next_line.h"

void	ft_error(const char *str, char c);
void	ft_putstr(const char *str);
void	execute_cmd(char *argv, char **envp);
char	**ft_split(const char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *str);
void	check_env(char **env);
void	ft_free_more(char *ptr, char **paths);
void	ft_free_memory(char **mtr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		open_file(char *argv, int i);
void	help_function_here_doc(int *fd, char *limiter, char *line);

#endif