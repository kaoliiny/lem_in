/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:18:28 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/11 23:52:42 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memalloc(size_t size)
{
	void	*x;

	if (!(x = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	return (x = ft_memset(x, '\0', size));
}
