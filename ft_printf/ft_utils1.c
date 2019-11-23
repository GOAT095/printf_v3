/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:29:29 by anassif           #+#    #+#             */
/*   Updated: 2019/11/23 14:31:04 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t l;
	size_t i;

	i = 0;
	l = ft_strlen((char *)src);
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (l);
}

char	*ft_strdup(const char *s1)
{
	char	*r;
	int		i;

	i = ft_strlen((char *)s1);
	r = malloc(sizeof(*s1) * (i + 1));
	if (r == NULL)
		return (NULL);
	ft_strlcpy(r, s1, i + 1);
	return (r);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	x;
	int				i;

	x = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == x)
			return ((char *)&s[i]);
		i++;
	}
	if (x == '\0')
		return ((char *)&s[i]);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
