/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 02:07:11 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/17 03:27:41 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texture_render(t_vars *v, void *txt, int y, int x)
{
	mlx_put_image_to_window(v->mlx, v->window, txt, y * 64, x * 64);
}

int	move_counter(t_vars *v)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	if (k <= 100)
	{
		if (k < 10)
			texture_render(v, v->txt->w, 1, 0);
		if (k < 100)
			texture_render(v, v->txt->w, 2, 0);
		k++;
	}
	i = 1;
	while (v->move / i >= 10)
		i *= 10;
	j = 0;
	while (i)
	{
		texture_render(v, v->txt->wc[v->move / i % 10], j++, 0);
		i /= 10;
	}
	return (0);
}

void	map_render(t_vars *v, int j, int i)
{
	if ((!(i - v->cm[0]) && !(j - v->cm[1]))
		|| (!(i - v->cm[0]) && (j - v->cm[1]) == 1)
		|| (!(i - v->cm[0]) && (j - v->cm[1]) == 2))
		return ;
	if (v->map[i][j] == '0' && (i != v->pl[0] || j != v->pl[1]))
		texture_render(v, v->txt->fl, j - v->cm[1], i - v->cm[0]);
	else if (v->map[i][j] == '1')
		texture_render(v, v->txt->w, j - v->cm[1], i - v->cm[0]);
	else if (v->map[i][j] == 'C')
		texture_render(v, v->txt->c[v->f % 7], j - v->cm[1], i - v->cm[0]);
	else if (v->map[i][j] == 'G')
		texture_render(v, v->txt->en, j - v->cm[1], i - v->cm[0]);
	else if (v->map[i][j] == 'E' && v->coll != 0
			&& (i != v->pl[0] || j != v->pl[1]))
		texture_render(v, v->txt->ec, j - v->cm[1], i - v->cm[0]);
	else if (v->map[i][j] == 'E' && v->coll == 0)
		texture_render(v, v->txt->eo, j - v->cm[1], i - v->cm[0]);
}

int	render_frame(t_vars *v)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = v->cm[0];
	y = v->cm[1];
	i = -1;
	while (v->map[++i][0])
	{
		j = -1;
		while (v->map[i][++j])
		{
			map_render(v, j, i);
		}
	}
	if (v->map[v->pl[0]][v->pl[1]] == 'E' && v->coll != 0)
		texture_render(v, v->txt->ecm, v->pl[1] - y, v->pl[0] - x);
	else
		texture_render(v, v->txt->p, v->pl[1] - y, v->pl[0] - x);
	move_counter(v);
	return (0);
}
