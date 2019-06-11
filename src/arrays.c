/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 23:19:07 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/12 00:13:51 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_array		*new_array(int def_size)
{
	int		i;
	t_array	*new_arr;

	i = 0;
	if (!(new_arr = ft_memalloc(sizeof(t_array))))
		manage_error(4);
	new_arr->size = 0;
	new_arr->limit = def_size - 1;
	if (!(new_arr->links = ft_memalloc(sizeof(t_room *) * def_size)))
		manage_error(4);
	while (i < def_size)
		new_arr->links[i++] = NULL;
	return (new_arr);
}

bool		expandable_array(t_array **old)
{
	int		i;
	t_room	**tmp_links;

	i = -1;
	tmp_links = (*old)->links;
	if ((*old)->limit < 100)
		(*old)->limit = (*old)->limit * 3;
	else
		(*old)->limit = (*old)->limit * 2;
	if (!((*old)->links = ft_memalloc(sizeof(t_room *) * (*old)->limit)))
		manage_error(4);
	while (++i < (*old)->size && tmp_links)
		(*old)->links[i] = tmp_links[i];
	(*old)->links[i++] = NULL;
	free(tmp_links);
	return (true);
}
