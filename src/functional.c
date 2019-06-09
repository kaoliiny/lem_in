/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:48:34 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/04 01:57:38 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_array	*new_array(int def_size)
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

bool	expandable_array(t_array **old)
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
	return (true);
}

t_room	*room_create(char *line)
{
	t_room		*new;
	const int	size = (ft_strchr(line, ' ') - line);

	if (!(new = ft_memalloc(sizeof(t_room))))
		manage_error(4);
	else
	{
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
	}
	return (new);
}

void	add_link(t_room *lst, char *line)
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
	while (tmp && !ft_strequ(tmp->name, name_from))
		(tmp->next) ? (tmp = tmp->next) : manage_error(5);
	while (tmp_2 && !ft_strequ(tmp_2->name, name_to))
		(tmp_2->next) ? (tmp_2 = tmp_2->next) : manage_error(5);
	if (!tmp->links)
		manage_error(9);
	while (tmp->links->links[i])
		++i && (i == tmp->links->limit) && (expandable_array(&tmp->links));
	(tmp->links->links[i] = tmp_2) && tmp->links->size++;
	tmp->links->links[++i] = NULL;
	i = 0;
	while (tmp_2->links->links[i])
		++i && (i == tmp_2->links->limit) && (expandable_array(&tmp_2->links));
	(tmp_2->links->links[i] = tmp) && tmp_2->links->size++;
	tmp_2->links->links[++i] = NULL;
}

bool	is_same_coords_or_name(char *line, t_room *tmp)
{
	char		*new_line;
	const char	*line_tmp = ft_strchr(line, ' ') + 1;

	new_line = ft_strdup(line);
	if (tmp->x == atoi(line_tmp)
		&& tmp->y == atoi(ft_strchr(line_tmp, ' ') + 1))
		manage_error(6);
	new_line[(int)(ft_strchr(line, ' ') - line)] = '\0';
	if (ft_strequ(new_line, tmp->name))
		manage_error(10);
	free(new_line);
	return (1);
}

bool	add_new_room(t_room **lst, t_struct *main, char *line, short status)
{
	t_room		*tmp;

	tmp = *lst;
	main->count_of_rooms++;
	if (!lst || !*lst || !(*lst)->name)
		(*lst = room_create(line)) &&
		(tmp = *lst);
	else
	{
		is_same_coords_or_name(line, tmp);
		while (tmp && tmp->next && (tmp = tmp->next))
			is_same_coords_or_name(line, tmp);
		tmp->next = room_create(line);
		tmp = tmp->next;
	}
	if ((status == START && main->start)
		|| (status == END && main->end))
		manage_error(7);
	(status == START) && (main->start = tmp);
	(status == END) && (main->end = tmp);
	return (true);
}
