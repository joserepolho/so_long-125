/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 02:18:55 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/15 17:14:09 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*bf;
	size_t	len;

	len = ft_strlen(s) + 1;
	bf = malloc(len * sizeof(char));
	if (!bf)
		return (0);
	ft_memcpy(bf, s, len);
	return (bf);
}

char	**clone_map(t_vars *v)
{
	int		i;
	char	**clone;

	i = 0;
	clone = malloc(((v->ms[0] + 1) * sizeof(char *)));
	if (!clone)
	{
		while (v->map[i][0])
		{
			free(clone[i]);
			i++;
		}
		ft_error_beginning("Error\nMemory allocation failed!");
	}
	while (v->map[i] && v->map[i][0])
	{
		clone[i] = ft_strdup(v->map[i]);
		i++;
	}
	clone[v->ms[0]] = malloc(1);
	clone[v->ms[0]][0] = '\0';
	return (clone);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'G')
		return ;
	map[y][x] = 'F';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}
