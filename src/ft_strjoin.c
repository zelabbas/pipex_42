/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:18:44 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/30 11:06:00 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*origin;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(((len_s1 + len_s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	origin = ptr;
	while (*s1)
	{
		*ptr++ = *s1++;
	}
	while (*s2)
	{
		*ptr++ = *s2++;
	}
	*ptr = '\0';
	return (origin);
}
