/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:17:21 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/18 17:50:09 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	if (len != 0)
	{
		d = dst;
		s = src;
		if ((*d++ = *s++) == '\0')
		{
			while (--len != 0)
				*d++ = '\0';
			return (dst);
		}
		while (--len != 0)
		{
			if ((*d++ = *s++) == '\0')
			{
				while (--len != 0)
					*d++ = '\0';
				break ;
			}
		}
	}
	return (dst);
}
