/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:32:08 by anassif           #+#    #+#             */
/*   Updated: 2019/11/19 20:32:23 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	char	ft_alpha(int i)
{
	if (i == 10)
		return ('A');
	if (i == 11)
		return ('B');
	if (i == 12)
		return ('C');
	if (i == 13)
		return ('D');
	if (i == 14)
		return ('E');
	if (i == 15)
		return ('F');
	return (0);
}

char			*ft_big_hexa(unsigned int x)
{
	int					y;
	int					i;
	unsigned int		nb;
	char				*s;

	y = 0;
	nb = x;
	if (x == 0)
		return ("0");
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
	return (ft_strrev(s));
}
