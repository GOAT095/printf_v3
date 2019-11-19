/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:41:23 by anassif           #+#    #+#             */
/*   Updated: 2019/11/19 15:58:44 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int	count_numbers(long int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long int n)
{
	char			*str;
	int				c;
	long int		nbr;

	nbr = 0;
	c = count_numbers(n);
	str = malloc(sizeof(char) * (c + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	str[c] = '\0';
	while (nbr > 0)
	{
		str[c-- - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}
