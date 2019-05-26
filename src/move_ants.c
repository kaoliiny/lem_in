/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:25:10 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/05/26 22:40:37 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

bool	ant_move(t_struct *main, t_room *old_room, t_room *new_room)
{
	new_room->full_of_ants = old_room->full_of_ants;
	old_room->full_of_ants = 0;
	ft_print(new_room->full_of_ants,
	new_room->name);
	if (new_room == main->end)
		main->ants_at_the_end++;
	return (1);
}

bool	reiteration(t_room **queue, t_room *find)
{
	int	i;

	i = 1;
	while (queue[i])
	{
		if (ft_strequ((queue[i])->name, find->name))
			return (1);
		i++;
	}
	return (0);
}

void	bfs_r(t_struct *main, t_room *tmp, t_room ***queue, int *count)
{
	int		j;
	int		i;

	j = 0;
	while (tmp && tmp->links && j < tmp->links->size)
	{
		if (tmp->full_of_ants && tmp->dst_from_end)
		{
			i = 0;
			while (tmp->full_of_ants && tmp->links->links[i] && tmp != main->start)
			{
				if (tmp->dst_from_end - 1
					== tmp->links->links[i]->dst_from_end &&
					(!tmp->links->links[i]->full_of_ants || tmp->links->links[i] == main->end))
					ant_move(main, tmp, tmp->links->links[i]);
				i++;
			}
		}
		if (!reiteration(*queue, tmp->links->links[j]))
		{
			((*queue)[*count] = tmp->links->links[j]);
			(*count)++;
		}
		j++;
	}
}

void	move_the_ants(t_struct *main, t_room **start, unsigned short size)
{
	int		i;
	int		counts;
	t_room	**queue;

	i = 0;
	queue = ft_memalloc(sizeof(t_room *) * (size + 2));
	i = 0;
	counts = 1;
	queue[i] = *start;
	while (queue[i] && i <= size + 1)
	{
		bfs_r(main, queue[i], &queue, &counts);
		i++;
	}
    free(queue);
}
