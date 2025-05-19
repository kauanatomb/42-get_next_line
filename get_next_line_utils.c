/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:11:50 by ktombola          #+#    #+#             */
/*   Updated: 2025/05/19 08:27:11 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (!s1)
		return (NULL);
	dest = malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, s1));
}

char	*ft_strjoin_and_free(char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (free(s1), NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (free(s1), NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	uc;

	uc = (char)c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == uc)
		{
			return ((char *)s);
		}
		s++;
	}
	if (uc == *s)
		return ((char *)s);
	return (0);
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
