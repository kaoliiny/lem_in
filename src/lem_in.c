/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:37:00 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/06/09 20:19:30 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	manage_error(int num)
{
	const char	*x[12] = {"",
	"\033[1;31musage: ./lem-in < [file]\033[0m",
	"\033[1;31musage: map error\033[0m",
	"\033[1;31musage: uncorrect count of ants\033[0m",
	"\033[1;31musage: malloc error\033[0m",
	"\033[1;31musage: links error\033[0m",
	"\033[1;31musage: rooms can't have the same coordinates\033[0m",
	"\033[1;31musage: error\nthere're more than one start/end points\033[0m",
	"\033[1;31musage: the beginning and the end are not related\033[0m",
	"\033[1;31musage: there're no rooms. Where the ants have to go?\033[0m",
	"\033[1;31musage: rooms can't have the same name\033[0m",
	};

	ft_putendl_fd(x[num], 2);
	exit(EXIT_FAILURE);
}

void	ft_print(int ant_num, char *room_name)
{
	ft_printf("L%s-%s", ft_itoa(ant_num), room_name);
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
	is_num(*line, manage_error, 2)
	&& (main->ants = ft_atoi(*line));
	if (main->ants <= 0 || main->ants > __INT32_MAX__)
		manage_error(2);
	main->ants_at_the_end = 0;
	main->ants_left_at_start = main->ants;
	ft_printf("%d\n", main->ants);
	free(*line);
}

int		main(int ac, char **av)
{
	t_array		ways;
	t_room		rooms;
	t_struct	main;
	char		*line;
	const int	fd = (av[1]) ? open(av[1], O_RDONLY) : 0;

	main.dst = 0;
	main.count_of_rooms = 0;
	ft_bzero(&main, sizeof(t_struct));
	ft_bzero(&rooms, sizeof(t_room));
	if (!get_next_line(fd, &line) || ac > 2)
		manage_error(1);
	add_count_of_ants(&main, &line);
	parsing_loop(fd, &rooms, &main, line);
	find_the_ways(&main, &ways);
	return (0);
}
