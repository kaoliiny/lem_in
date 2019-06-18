/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:43:09 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:46:59 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	f;

	if (ft_strcmp(needle, "") == 0 || ft_strcmp(haystack, needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		f = 0;
		while (haystack[i + f] == needle[f] && (i + f) < len)
		{
			f++;
			if (!needle[f])
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
