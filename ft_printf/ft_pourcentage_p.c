/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcentage_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 20:33:01 by anassif           #+#    #+#             */
/*   Updated: 2019/11/24 14:55:24 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	char	ft_alpha(int i)
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
	else
		return (i + '0');
	return (0);
}

static int		ft_county(unsigned long long nb)
{
	int y;

	y = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		y++;
	}
	return (y);
}

char			*ft_p(unsigned long long x)
{
	int					y;
	int					i;
	unsigned long long	nb;
	char				*s;

	nb = x;
	y = ft_county(nb);
	if (x == 0)
		return ("0x0");
	if (!(s = malloc(sizeof(char) * y + 3)))
		return (NULL);
	i = 2;
	s[0] = '0';
	s[1] = 'x';
	while (y--)
	{
		nb = x % 16;
		s[i] = ft_alpha(nb);
		x = x / 16;
		i++;
	}
	s[i] = '\0';
	ft_strrev(s + 2);
	return (s);
}
