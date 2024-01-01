/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:32:18 by zelabbas          #+#    #+#             */
/*   Updated: 2023/12/30 11:22:08 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		size = 0;
	else if (slen - start < len)
		size = (slen - start);
	else
		size = len;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*ptr;
// 	char	*origin;
// 	int		len_s1;
// 	int		len_s2;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	len_s1 = ft_strlen(s1);
// 	len_s2 = ft_strlen(s2);
// 	ptr = (char *)malloc(((len_s1 + len_s2) + 1) * sizeof(char));
// 	if (!ptr)
// 		return (NULL);
// 	origin = ptr;
// 	while (*s1)
// 	{
// 		*ptr++ = *s1++;
// 	}
// 	while (*s2)
// 	{
// 		*ptr++ = *s2++;
// 	}
// 	*ptr = '\0';
// 	return (origin);
// }
