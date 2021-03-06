/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:25:10 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/25 19:08:52 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ant_move_from_start(t_struct *main, t_room *to)
{
	if (main->ants_left_at_start)
	{
		main->ants_left_at_start--;
		to->full_of_ants =
		main->ants - main->ants_left_at_start;
		ft_print(to->full_of_ants, to->name);
		if (to == main->end)
		{
			main->ants_at_the_end++;
			ft_printf(" ");
			ant_move_from_start(main, to);
		}
	}
}

static bool	ant_move(t_struct *main, t_room *old_room, t_room *new_room)
{
	new_room->full_of_ants = old_room->full_of_ants;
	old_room->full_of_ants = 0;
	(main->space) && ft_printf(" ");
	ft_print(new_room->full_of_ants, new_room->name);
	main->space = true;
	if (new_room == main->end)
		main->ants_at_the_end++;
	return (1);
}

void		rev_ways(t_struct *main, t_room **old, char *av)
{
	t_room	*tmp;
	t_room	*prev;
	t_room	*current;

	if (!(*old)->parent)
		return ;
	prev = *old;
	current = (*old)->parent;
	ft_strequ(av, "-w") &&
	ft_printf("[%s]->[%s]", main->start->name, (*old)->name);
	(*old)->parent = NULL;
	while (current->parent && current->parent != main->end)
	{
		ft_strequ(av, "-w") && ft_printf("->[%s]", current->name);
		tmp = current;
		current = current->parent;
		tmp->parent = prev;
		prev = tmp;
	}
	*old = current;
	current->parent = prev;
	ft_strequ(av, "-w")
	&& ft_printf("->[%s]->[%s]\n", current->name, main->end->name);
}

bool		move_the_ants_from_start(t_struct *main, t_array *ways)
{
	int		i;
	int		dst;
	t_room	*tmp;

	i = 0;
	while (ways->links[i])
	{
		dst = 3;
		tmp = ways->links[i];
		while (tmp && tmp->parent && dst++)
			tmp = tmp->parent;
		if ((!tmp->full_of_ants || ways->links[i] == main->end)
			&& main->ants_left_at_start)
			if ((dst * i - main->dst) < main->ants_left_at_start)
			{
				(main->space) && ft_printf(" ");
				(!main->space) && (main->space = 1);
				ant_move_from_start(main, tmp);
				main->dst += dst;
			}
		i++;
	}
	main->dst = 0;
	return (true);
}

void		move_the_ants(t_struct *main, t_array *ways, char *av)
{
	int		i;
	t_room	*tmp;

	i = 0;
	if (!ways->links[i])
		manage_error(5);
	while (ways && ways->links[i])
		rev_ways(main, ways->links + i++, av);
	ft_strequ(av, "-w") && ft_printf("\n" RESET);
	while (!(main->ants_at_the_end == main->ants) && (i = 0) | 1)
	{
		main->space = false;
		while (ways->links[i] && !(main->ants_at_the_end == main->ants))
		{
			tmp = ways->links[i++];
			if (tmp->full_of_ants && tmp != main->end)
				ant_move(main, tmp, main->end);
			while (tmp && tmp->parent && !(main->ants_at_the_end == main->ants))
			{
				(tmp->parent->full_of_ants) && ant_move(main, tmp->parent, tmp);
				tmp = tmp->parent;
			}
		}
		move_the_ants_from_start(main, ways) && ft_printf("\n");
	}
}
