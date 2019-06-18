/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:57:31 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:47:20 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool		ft_bfree(void *arr)
{
	if (!arr)
		return (true);
	free(arr);
	return (true);
}
