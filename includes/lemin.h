/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:49:01 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/02 20:17:00 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# define MAX_COUNT_OF_WAYS 20
# define START 1
# define END -1

typedef struct s_room			t_room;
typedef struct s_array			t_array;
typedef struct s_main_struct	t_struct;

struct	s_room
{
	t_array			*links;
	t_room			*parent;
	t_room			*next;
	char			*name;
	int				x;
	int				y;
	short			dst_from_end;
	unsigned short	full_of_ants;
	bool			visited;
};

struct	s_array
{
	t_room			**links;
	unsigned short	limit;
	unsigned short	size;
};

struct	s_main_struct
{
	t_room			*start;
	t_room			*end;
	int				ants;
	int				dst;
	int				ants_at_the_end;
	short			ants_left_at_start;
	unsigned short	count_of_rooms;
	bool			space;
};

t_array *new_array(int def_size);

t_room	*room_create(char *line);

bool	add_new_room(t_room **lst, t_struct *main, char *line, short status);

void	add_link(t_room *lst, char *line);

t_room	*bfs(t_struct *main, t_room **start, unsigned short size);

void	find_the_ways(t_struct *main, t_array *ways);

void	move_the_ants(t_struct *main, t_array *ways);

void	ft_print(int ant_num, char *room_name);

void	manage_error(int num);

#endif
