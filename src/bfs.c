/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:08:55 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/05/29 20:14:21 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

bool	ant_move_from_start(t_struct *main, int i)
{
	main->ants_left_at_start--;
	main->start->links->links[i]->full_of_ants =
	main->ants - main->ants_left_at_start;
	ft_print(main->start->links->links[i]->full_of_ants,
	main->start->links->links[i]->name);
	if (main->start->links->links[i] == main->end)
		main->ants_at_the_end++;
	return (1);
}

void	ways_init(t_array ***ways)
{
	int	i;

	i = 0;
	if (!(*ways = ft_memalloc(sizeof(t_array *) * (MAX_COUNT_OF_WAYS + 1))))
		manage_error(4);
	while (i < MAX_COUNT_OF_WAYS)
		(*ways)[i++] = new_array(4);
}

int		min(t_room *link)
{
	int		i;
	int		j;
	int		min;
	t_room	*tmp;
	int		rez;
	// t_room	*tmp_2;

	i = 0;
	min = 0;
	tmp = link;
	while (tmp->links->links[i])
	{
		if (tmp->links->links[i]->dst_from_end + 1 == tmp->dst_from_end)
		{
			j = 0;
			while (tmp->links->links[i]->links->links[j])
				j++;
			(!min) && (min = j) && (rez = i);
			(j < min) && (min = j) && (rez = i);
		}
		i++;
	}
	return (rez);
}

bool	simplest_way(t_struct *main, t_array **ways, int way_num)
{
	int		step;
	int		i;
	int		j;
	t_room	*best_way;

	i = 0;
	j = 0;
	step = 0;
	while (main->start->links->links[i])
	{
		best_way = main->start->links->links[i];
		if (!best_way->visited)
		{
			(!best_way->full_of_ants || best_way == main->end)
			&& (ways[way_num]->links[step++] = best_way)
			&& (best_way->visited = 1);
			ant_move_from_start(main, i);
			if (best_way == main->end)
				return (1);
			else
				while (best_way && best_way->links->links[j])
				{
					if (best_way->links->links[j]->dst_from_end + 1
						== best_way->dst_from_end)
						{
							best_way = best_way->links->links[min(best_way)];
							(ways[way_num]->links[step++] = best_way);
							best_way->visited = 1;
							if (best_way == main->end)
								return (1);
							j = 0;
						}
					else
						j++;
				}
		}
		i++;
	}
	return (0);
}

void	find_the_ways(t_array ***ways, t_struct *main)
{
	int	i;
	t_room *tmp;

	i = 0;
	ways_init(ways);
	while (simplest_way(main, *ways, i))
	{
		tmp = main->start;
		while (tmp->next)
		{
			tmp->dst_from_end = -1;
			tmp = tmp->next;
		}
		tmp->dst_from_end = -1;
		bfs(&main->end, main->count_of_rooms);
		i++;
	}
}

void	bfs_recovering(int *counts, t_room *tmp, t_room ***queue)
{
	int		j;
	short	*dst;
	short	*dst_of_j_point;

	j = 0;
	dst = &tmp->dst_from_end;
	while (tmp && tmp->links && j < tmp->links->size)
	{
		dst_of_j_point = &tmp->links->links[j]->dst_from_end;
		(*dst == -1) && (*dst = 0);
		if (tmp && tmp->links->links[j] && *dst_of_j_point == -1
		&& !tmp->links->links[j]->visited)
		{
			(*queue)[*counts] = tmp->links->links[j];
			*dst_of_j_point = (*dst + 1);
			(*counts)++;
		}
		j++;
	}
}

void	bfs(t_room **start, unsigned short size)
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
		bfs_recovering(&counts, queue[i], &queue);
		i++;
	}
	free(queue);
}
