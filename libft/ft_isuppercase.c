/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuppercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 01:21:28 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:47:41 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isuppercase(const int c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}