/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:08:55 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/17 15:45:06 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		bfs_recovering(int *counts, t_room *tmp, t_room ***queue)
{
	int		j;
	short	*dst;
	short	*dst_of_j_point;

	j = 0;
	dst = &tmp->dst_from_end;
	while (j < tmp->links->size)
	{
		dst_of_j_point = &tmp->links->links[j]->dst_from_end;
		(*dst == -1) && (*dst = 0);
		if (tmp->links->links[j] && !tmp->links->links[j]->visited)
		{
			tmp->links->links[j]->visited = 1;
			tmp->links->links[j]->parent = tmp;
			(*queue)[*counts] = tmp->links->links[j];
			*dst_of_j_point = (*dst + 1);
			(*counts)++;
		}
		j++;
	}
}

static t_room	*bfs(t_struct *main, t_room *start, unsigned short size)
{
	int		i;
	t_room	*tmp;
	int		counts;
	t_room	**queue;

	i = 0;
	queue = ft_memalloc(sizeof(t_room *) * (size + 2));
	counts = 1;
	queue[i] = start;
	queue[i]->visited = 1;
	while (queue[i] && i < size)
	{
		bfs_recovering(&counts, queue[i], &queue);
		if (queue[i] == main->start)
		{
			tmp = queue[i]->parent;
			free(queue);
			return (tmp);
		}
		i++;
	}
	free(queue);
	return (0);
}

void			find_the_ways(t_struct *main, t_array *ways)
{
	int		i;
	int		j;
	t_room	*tmp;

	i = -1;
	ways = new_array(100);
	while ((ways->links[++i] = bfs(main, main->end, main->count_of_rooms)) && !(ways->links[i] == main->end))
	{
		if (i == 0 && main->start->dst_from_end == -1)
			manage_error(8);
		tmp = main->start;
		while (tmp->next)
		{
			tmp->visited = 0;
			tmp->dst_from_end = -1;
			tmp = tmp->next;
		}
		j = -1;
		tmp->visited = 0;
		tmp->dst_from_end = -1;
		while ((tmp = ways->links[++j]))
			while (tmp && tmp->parent && (tmp->visited = 1))
				tmp = tmp->parent;
	}
	move_the_ants(main, ways);
}
