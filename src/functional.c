/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:48:34 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/18 20:25:51 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		is_room_exist(t_room **tmp, char *name_from)
{
	while ((*tmp) && !ft_strequ((*tmp)->name, name_from))
		((*tmp)->next) ? ((*tmp) = (*tmp)->next) : manage_error(5);
	if (!(*tmp)->links)
		manage_error(9);
}

void		add_link(t_room *lst, char *line)
{
	int		i;
	t_room	*tmp;
	t_room	*tmp_2;
	char	name_from[50];
	char	*name_to;

	i = 0;
	tmp = lst;
	tmp_2 = lst;
	name_to = ft_strdup(ft_strchr(line, '-') + 1);
	ft_memcpy(name_from, line, (int)(ft_strchr(line, '-') - line));
	name_from[(int)(ft_strchr(line, '-') - line)] = '\0';
	is_room_exist(&tmp, name_from);
	is_room_exist(&tmp_2, name_to);
	while (tmp->links->links[i])
		++i && (i == tmp->links->limit) && (expandable_array(&tmp->links));
	(tmp->links->links[i] = tmp_2) && tmp->links->size++;
	tmp->links->links[++i] = NULL;
	i = 0;
	while (tmp_2->links->links[i])
		++i && (i == tmp_2->links->limit) && (expandable_array(&tmp_2->links));
	(tmp_2->links->links[i] = tmp) && tmp_2->links->size++;
	tmp_2->links->links[++i] = NULL;
	free(name_to);
}

t_room		*room_create(char *line)
{
	t_room		*new;
	const int	size = ft_strchr(line, ' ') - line;

	if (!(new = ft_memalloc(sizeof(t_room))))
		manage_error(4);
	new->name = ft_memalloc(sizeof(char) * (size + 1));
	ft_memcpy(new->name, line, size);
	line = ft_strchr(line, ' ') + 1;
	new->x = ft_atoi(line);
	line = ft_strchr(line, ' ') + 1;
	new->y = ft_atoi(line);
	new->dst_from_end = -1;
	new->links = new_array(4);
	new->full_of_ants = 0;
	new->visited = false;
	new->parent = NULL;
	new->next = NULL;
	return (new);
}

static bool	is_same_coords_or_name(char *line, t_room *tmp)
{
	const char	*x_in_line = ft_strchr(line, ' ') + 1;
	const char	*y_in_line = ft_strchr(x_in_line, ' ') + 1;
	char		name[128];

	if (tmp->x == atoi(x_in_line)
		&& tmp->y == atoi(y_in_line))
		manage_error(6);
	ft_bzero(name, 128);
	ft_memcpy(name, line, x_in_line - line - 1);
	if (ft_strequ(name, tmp->name))
		manage_error(10);
	return (true);
}

bool		add_new_room(t_room **rooms,
			t_struct *main, char *line, short status)
{
	t_room		*tmp;

	main->count_of_rooms++;
	tmp = *rooms;
	if (tmp->name == NULL)
		tmp =
		*rooms = room_create(line);
	else
	{
		while (tmp->next)
			is_same_coords_or_name(line, tmp)
			&& (tmp = tmp->next);
		is_same_coords_or_name(line, tmp);
		tmp->next = room_create(line);
		tmp = tmp->next;
	}
	if ((status == START && main->start)
		|| (status == END && main->end))
		manage_error(7);
	if (status == START)
		(main->start = tmp);
	if (status == END)
		(main->end = tmp);
	return (true);
}
