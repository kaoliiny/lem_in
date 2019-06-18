/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 02:23:33 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:47:36 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			ft_itoc(const unsigned char value, const bool is_upperсase)
{
	if (value < 10)
		return (value + '0');
	return (value - 10 + (is_upperсase ? 'A' : 'a'));
}
