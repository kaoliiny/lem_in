/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:18:32 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:47:18 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_atou_base(const char *s, int base)
{
	size_t		res;
	char		c;

	res = 0;
	while (ft_iswhitespace(*s))
		s++;
	while (*s && ft_isalnum(*s))
	{
		c = ft_tolower(*s);
		c -= (ft_isalpha(c)) ? ('a' - 10) : '0';
		if (c >= base)
			return (res);
		res = res * base + c;
		s++;
	}
	return (res);
}
