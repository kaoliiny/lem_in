/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:08:55 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/05/26 23:29:19 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

bool	ant_move_from_start(t_struct *main, int i)
{
	main->ants_left_at_start--;
	main->start->links->links[i]->full_of_ants
	= main->ants - main->ants_left_at_start;
	ft_print(main->start->links->links[i]->full_of_ants,
	main->start->links->links[i]->name);
	if (main->start->links->links[i] == main->end)
		main->ants_at_the_end++;
	return (1);
}

bool	find_simplest_way(t_struct *main)
{
	int	i;

	i = 0;
	while (main->start->links->links[i])
	{
		while ((main->start->dst_from_end - 1) == main->start->links->links[i]->dst_from_end)
		{
			(!main->start->links->links[i]->full_of_ants
			|| main->start->links->links[i] == main->end) && ant_move_from_start(main, i);
			if (!(main->start->links->links[i] == main->end) || !main->ants_left_at_start)
				return (1);
		}
		i++;
	}
	return (1);
}

void	bfs_recovering(int *counts, t_room *tmp, t_room	***queue, bool start_end)
{
	int		j;
	short	*dst;
	short	*dst_of_j_point;

	j = 0;
	dst = (start_end) ? &tmp->dst_from_start : &tmp->dst_from_end;
	while (tmp && tmp->links && j < tmp->links->size)
	{
		dst_of_j_point = (start_end) ? &tmp->links->links[j]->dst_from_start
		: &tmp->links->links[j]->dst_from_end;
		(*dst == -1) && (*dst = 0);
		if (*dst_of_j_point == -1)
		{
			(*queue)[*counts] = tmp->links->links[j];
			*dst_of_j_point = (*dst + 1);
			(*counts)++;
		}
		j++;
	}
}

void	bfs(t_room **start, unsigned short size, bool start_end)
{
	int		i;
	int		counts;
	t_room	**queue;

	i = 0;
	queue = ft_memalloc(sizeof(t_room *) * size + 2);
	i = 0;
	counts = 1;
	queue[i] = *start;
	while (queue[i] && i < size)
	{
		bfs_recovering(&counts, queue[i], &queue, start_end);
		i++;
	}
	free(queue);
}