/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:36:20 by anassif           #+#    #+#             */
/*   Updated: 2019/11/11 14:23:32 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_strrev(char *str)
{
	int x;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i - 1 > j)
	{
		x = str[i - 1];
		str[i - 1] = str[j];
		str[j] = x;
		j++;
		i--;
	}
	return (str);
}

static char	ft_alpha(int i)
{
	if (i == 10)
		return ('a');
	if (i == 11)
		return ('b');
	if (i == 12)
		return ('c');
	if (i == 13)
		return ('d');
	if (i == 14)
		return ('e');
	if (i == 15)
		return ('f');
	return (0);
}

void		ft_small_hexa(unsigned int x)
{
	int					y;
	int					i;
	unsigned int		nb;
	char				*s;

	y = 0;
	nb = x;
	while (nb > 0)
	{
		nb = nb / 16;
		y++;
	}
	s = malloc(sizeof(char) * y + 1);
	i = 0;
	while (y--)
	{
		nb = x % 16;
		if (nb > 9 && nb < 16)
			s[i] = ft_alpha(nb);
		else
			s[i] = nb + '0';
		x = x / 16;
		i++;
	}
	s[i] = '\0';
	ft_putstr(ft_strrev(s));
}
