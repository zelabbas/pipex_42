/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:42:16 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/30 14:38:36 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_more(char *ptr, char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	if (*ptr)
		free(ptr);
	ft_error(
		"\033[1;31m🛑ERROR : in step path (path incorrect)!\n\033[0m", 't');
}

void	ft_free_memory(char **mtr)
{
	int	i;

	i = -1;
	while (mtr[++i])
		free(mtr[i]);
	free(mtr);
}
