/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:11:44 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:49:37 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(size_t value, const int base, const bool is_upperсase)
{
	int				j;
	size_t			b;
	char			*res;

	if (base > 16 || base < 2)
		return (0);
	j = 1;
	b = value;
	while (b /= base)
		j++;
	b = value;
	res = (char *)malloc(sizeof(char) * j);
	res[j--] = '\0';
	if (value == 0)
		res[0] = '0';
	while (b)
	{
		res[j--] = ft_itoc(b % base, is_upperсase);
		b /= base;
	}
	return (res);
}
