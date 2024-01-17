/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:22:04 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/16 20:49:57 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_colls(t_vars *v)
{
	if (v->txt->c)
	{
		mlx_destroy_image(v->mlx, v->txt->c[0]);
		mlx_destroy_image(v->mlx, v->txt->c[1]);
		mlx_destroy_image(v->mlx, v->txt->c[2]);
		mlx_destroy_image(v->mlx, v->txt->c[3]);
		free(v->txt->c[7]);
		free(v->txt->c);
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i][0])
		{
			free(map[i]);
			i++;
		}
		if (map[i])
			free(map[i]);
		free(map);
	}
}

void	free_walls(t_vars *v)
{
	if (v->txt->w)
		mlx_destroy_image(v->mlx, v->txt->w);
	if (v->txt->wc)
	{
		mlx_destroy_image(v->mlx, v->txt->wc[0]);
		mlx_destroy_image(v->mlx, v->txt->wc[1]);
		mlx_destroy_image(v->mlx, v->txt->wc[2]);
		mlx_destroy_image(v->mlx, v->txt->wc[3]);
		mlx_destroy_image(v->mlx, v->txt->wc[4]);
		mlx_destroy_image(v->mlx, v->txt->wc[5]);
		mlx_destroy_image(v->mlx, v->txt->wc[6]);
		mlx_destroy_image(v->mlx, v->txt->wc[7]);
		mlx_destroy_image(v->mlx, v->txt->wc[8]);
		mlx_destroy_image(v->mlx, v->txt->wc[9]);
		free(v->txt->wc[10]);
		free(v->txt->wc);
	}
}

int	free_all(t_vars *v)
{
	if (v->txt)
	{
		if (v->txt->p)
			mlx_destroy_image(v->mlx, v->txt->p);
		free_walls(v);
		if (v->txt->fl)
			mlx_destroy_image(v->mlx, v->txt->fl);
		free_colls(v);
		if (v->txt->eo)
			mlx_destroy_image(v->mlx, v->txt->eo);
		if (v->txt->ec)
			mlx_destroy_image(v->mlx, v->txt->ec);
		if (v->txt->ecm)
			mlx_destroy_image(v->mlx, v->txt->ecm);
		if (v->txt->en)
			mlx_destroy_image(v->mlx, v->txt->en);
		free(v->txt);
	}
	free_mlx(v);
	free_map(v->map);
	exit(0);
	return (0);
}
