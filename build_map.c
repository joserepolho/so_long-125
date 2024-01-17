/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:31:05 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/17 02:13:41 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_beginning(char *err)
{
	perror(err);
	exit(1);
}

char	**build_map(int fd, int width)
{
	int		i;
	char	*ln;
	char	**map;

	map = malloc(((width + 1) * sizeof(char *)));
	if (!map)
		return (0);
	i = 0;
	ln = get_next_line(fd);
	while (ln && ln[0])
	{
		if (ln[0])
			map[i] = ln;
		else
			free(ln);
	ln = get_next_line(fd);
	i++;
	}
	if (ln)
		free(ln);
	map[width] = malloc(1);
	map[width][0] = '\0';
	return (map);
}

int	map_width(int fd)
{
	int		i;
	char	*ln;

	i = 0;
	ln = get_next_line(fd);
	while (ln && ln[0])
	{
		i++;
		free(ln);
		ln = get_next_line(fd);
	}
	if (ln)
		free(ln);
	return (i);
}

void	mapping(t_vars *v, char **av)
{
	int	i;
	int	fd;

	i = ft_strlen(av[1]);
	if (av[1][i - 4] != '.' || av[1][i - 3] != 'b'
		|| av[1][i - 2] != 'e' || av[1][i - 1] != 'r')
		ft_error_beginning("Error\nNeeds to be a .ber file!\n");
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		ft_error_beginning("Error\nCould not open file.\n");
	v->ms[0] = map_width(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		ft_error_beginning("Error\nCould not open file.\n");
	v->map = build_map(fd, v->ms[0]);
	if (v->map[0][0] == '\0')
		checks_error(v->map, "Error\nNo map!\n");
	close(fd);
	v->ms[1] = ft_strlen(v->map[0]);
	check_map(v);
	check_components(v);
	player_pos(v->map, v->pl);
	check_path(v);
}
