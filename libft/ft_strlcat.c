/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:36:05 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:46:57 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;
	size_t	j;
	size_t	n;

	n = size;
	dstlen = 0;
	while (dst[dstlen] && n-- != 0)
		dstlen++;
	n = size - dstlen;
	i = dstlen;
	j = 0;
	if (n-- == 0)
		return (dstlen + ft_strlen(src));
	while (src[j])
	{
		if (n != 0)
		{
			*(dst + i++) = src[j];
			n--;
		}
		j++;
	}
	*(dst + i) = '\0';
	return (dstlen + j);
}
