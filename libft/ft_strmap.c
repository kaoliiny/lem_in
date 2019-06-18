/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:15:43 by vbrazas           #+#    #+#             */
/*   Updated: 2019/06/18 17:48:37 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*buf;

	if (s == NULL || f == NULL)
		return (NULL);
	buf = (char *)malloc(sizeof(*buf) * (ft_strlen(s) + 1));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buf[i] = f(s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
