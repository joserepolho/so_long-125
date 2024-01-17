/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:29:33 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/15 18:42:24 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_vars *v)
{
	int	i;

	i = 0;
	while (v->map[i][0] && ft_strlen(v->map[i]) == v->ms[1])
		i++;
	if (v->map[i][0])
		checks_error(v->map, "Error\nThe map is not rectangular!\n");
	i = 0;
	while (v->map[i][0] == '1' && v->map[i][v->ms[1] - 2] == '1')
		i++;
	if (v->map[i][0] && v->map[i][v->ms[1] - 2])
		checks_error(v->map, "Error\nMap not closed!\n");
	i = 0;
	while (v->map[0][i] == '1' && v->map[v->ms[0] - 1][i] == '1')
		i++;
	if (v->map[0][i] != '\n' && v->map[v->ms[0] - 1][i])
		checks_error(v->map, "Error\nMap not closed!\n");
}

int	count_components(char **map, int *c, int *e, int *p)
{
	int	i;
	int	j;

	i = -1;
	*c = 0;
	*e = 0;
	*p = 0;
	while (map[++i] && map[i][0])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				(*c)++;
			else if (map[i][j] == 'E')
				(*e)++;
			else if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] != '0' && map[i][j] != '1' &&
					map[i][j] != '\n' && map[i][j] != 'F' && map[i][j] != 'G')
				return (0);
		}
	}
	return (1);
}

void	check_components(t_vars *v)
{
	int	c;
	int	e;
	int	p;

	if (!count_components(v->map, &c, &e, &p))
		checks_error(v->map, "Error\nMap contains invalid characters!\n");
	v->coll = c;
	if (!c)
		checks_error(v->map, "Error\nNo collectibles found!\n");
	if (e != 1)
		checks_error(v->map, "Error\nMap must contain 1 exit only!\n");
	if (p != 1)
		checks_error(v->map, "Error\nMap must contain 1 player position only!\n");
}

void	check_path(t_vars *v)
{
	int		i;
	int		c;
	int		e;
	int		p;
	char	**map_clone;

	map_clone = clone_map(v);
	flood_fill(map_clone, v->pl[0], v->pl[1]);
	i = -1;
	if (count_components(map_clone, &c, &e, &p) && (c || e || p))
	{
		while (v->map[++i][0])
			free(map_clone[i]);
		free(map_clone[i]);
		free(map_clone);
		checks_error(v->map, "Error\nMap has blocked path!\n");
	}
	i = -1;
	while (v->map[++i][0])
		free(map_clone[i]);
	free(map_clone[i]);
	free(map_clone);
}
