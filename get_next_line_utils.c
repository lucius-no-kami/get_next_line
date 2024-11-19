/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luluzuri <luluzuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:35:20 by luluzuri          #+#    #+#             */
/*   Updated: 2024/11/19 13:54:14 by luluzuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	}
	else
	{
		while (i < n)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dest);
}

static size_t	ft_strlen(const char *s)
{
	const char	*move = s;

	while (*move)
		move++;
	return (move - s);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	int		i;

	slen = ft_strlen(s);
	i = 0;
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (sub);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *s)
{
	char	*sub;
	int		slen;
	int		i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	sub = (char *)malloc((slen + 1) * sizeof(char));
	if (!sub)
		return (sub);
	i = 0;
	while (i < slen)
	{
		sub[i] = s[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	flen;
	size_t	slen;
	char	*sub;
	int		i;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	flen = ft_strlen(s1);
	slen = ft_strlen(s2);
	sub = (char *)malloc((slen + flen + 1) * sizeof(char));
	if (!sub)
		return (sub);
	i = 0;
	ft_memmove(sub, s1, flen);
	ft_memmove(sub + flen, s2, slen);
	sub[flen + slen] = '\0';
	free((void *)s1);
	return (sub);
}
