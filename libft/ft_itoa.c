/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:28:07 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:47:58 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*buf;
	long	i;
	long	nn;
	short	j;

	i = 10;
	j = 2;
	nn = n;
	if (n < 0)
	{
		nn = -nn;
		j++;
	}
	while (nn / i > 0 && ++j)
		i *= 10;
	buf = (char *)malloc(sizeof(char) * j);
	if (buf == NULL)
		return (NULL);
	j = 0;
	if (n < 0)
		buf[j++] = '-';
	while ((i /= 10) > 0)
		buf[j++] = (nn / i) % 10 + '0';
	buf[j] = '\0';
	return (buf);
}
