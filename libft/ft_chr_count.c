/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:54:25 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/18 17:47:22 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chr_count(char *line, char symbol)
{
	int		i;

	i = 0;
	while (*line)
	{
		if (*line == symbol)
			i++;
		line++;
	}
	return (i);
}
