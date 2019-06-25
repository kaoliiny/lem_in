/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:37:00 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/25 19:26:13 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	manage_error(int num)
{
	const char	*x[12] = {"",
	RED "usage: ./lem-in [-w] < [file]" RESET,
	RED "usage: map error" RESET,
	RED "usage: uncorrect count of ants" RESET,
	RED "usage: malloc error" RESET,
	RED "usage: links error" RESET,
	RED "usage: rooms can't have the same coordinates" RESET,
	RED "usage: error\nthere're more than one start/end points" RESET,
	RED "usage: the beginning and the end are not related" RESET,
	RED "usage: there're no rooms. Where the ants have to go?" RESET,
	RED "usage: rooms can't have the same name" RESET,
	};

	ft_putendl_fd(x[num], 2);
	exit(EXIT_FAILURE);
}

void	ft_print(int ant_num, char *room_name)
{
	ft_printf("L%d-%s", ant_num, room_name);
}

void	parsing_loop(int fd, t_room *rooms, t_struct *main, char *line)
{
	int			byte;
	short		status;

	status = 0;
	while ((byte = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == '#')
		{
			(ft_strequ(line, "##start")) && (status = START);
			(ft_strequ(line, "##end")) && (status = END);
		}
		else if (ft_chr_count(line, ' ') == 2
			&& !(*line == 'L') && !(*line == '#'))
			add_new_room(&rooms, main, line, status) && (status = 0);
		else if (ft_strchr(line, '-'))
			add_link(rooms, line);
		else
			manage_error(2);
		ft_printf("%s\n", line);
		free(line);
	}
	if (byte < 0 || !main->start || !main->end)
		manage_error(2);
	ft_printf("\n");
}

void	add_count_of_ants(t_struct *main, char **line)
{
	is_num(*line, manage_error, 3)
	&& (main->ants = ft_atoi(*line));
	if (main->ants <= 0 || main->ants > __INT32_MAX__)
		manage_error(3);
	main->ants_at_the_end = 0;
	main->ants_left_at_start = main->ants;
	ft_printf("%d\n", main->ants);
	free(*line);
}

int		main(int ac, char **av)
{
	t_array		*ways;
	t_room		*rooms;
	t_struct	*main;
	char		*line;

	ways = new_array(100);
	main = ft_memalloc(sizeof(t_struct));
	rooms = ft_memalloc(sizeof(t_room));
	main->dst = 0;
	main->count_of_rooms = 0;
	if (!get_next_line(0, &line) || ac > 2 || !av)
		manage_error(1);
	add_count_of_ants(main, &line);
	parsing_loop(0, rooms, main, line);
	ft_strequ(av[1], "-w") && ft_printf(YELLOW "Found ways:\n");
	find_the_ways(main, ways, av[1]);
	return (0);
}
