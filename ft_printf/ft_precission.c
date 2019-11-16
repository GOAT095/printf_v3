/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precission.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:29:19 by anassif           #+#    #+#             */
/*   Updated: 2019/11/16 22:34:10 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_precission(char *str, int j)
{
	int		i;
	char	*s;

	i = strlen(str);
	if (j > i)
	{
		s = malloc(i + j + 1);
		memset(s, '0', j - i);
		strlcpy(s + j - i, str, i + 1);
	}
	else
	{
		strlcat(s, str, i);
	}
	return (s);
}
