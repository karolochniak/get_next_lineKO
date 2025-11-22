/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 23:50:52 by kochniak          #+#    #+#             */
/*   Updated: 2025/11/22 11:05:29 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	if (!s1)
	{
		dest = malloc(1);
		if (!dest)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	len = ft_strlen(s1);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*tmp;

	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strdup(s2));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	tmp = malloc(l1 + l2 + 1);
	if (!tmp)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(tmp, s1, l1 + 1);
	ft_strlcpy(tmp + l1, s2, l2 + 1);
	free(s1);
	return (tmp);
}

char	*ft_strchr(const char *str, int z)
{
	size_t	i;
	char	znak;

	if (!str)
		return (NULL);
	i = 0;
	znak = (char)z;
	while (str[i] != '\0')
	{
		if (str[i] == znak)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == znak)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
