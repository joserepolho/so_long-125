/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_of_mass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:23:17 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/17 02:30:40 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_center_of_mass(t_vars *v)
{
	mlx_get_screen_size(v->mlx, &v->ss[1], &v->ss[0]);
	v->ss[0] = fmin(v->ss[0] / 64, v->ms[0]);
	v->ss[1] = fmin(v->ss[1] / 64, v->ms[1]);
	v->cm[0] = fmin(v->pl[0] - v->ss[0] / 2, v->ss[0]) - 1;
	if (v->cm[0] < 0)
		v->cm[0] = 0;
	v->cm[1] = fmin(v->pl[1] - v->ss[1] / 2, v->ss[1]);
	if (v->cm[1] < 0)
		v->cm[1] = 0;
}

void	check_center_of_mass(t_vars *v, int *m)
{
	if ((m[0] < 0 && v->pl[0] - v->cm[0] < v->ss[0] / 2 && v->cm[0] + m[0] >= 0)
		|| (m[0] > 0 && v->pl[0] - v->cm[0] > v->ss[0] / 2
			&& v->cm[0] + m[0] <= v->ms[0] - v->ss[0]))
		v->cm[0] += m[0];
	if ((m[1] < 0 && v->pl[1] - v->cm[1] < v->ss[1] / 2 && v->cm[1] + m[1] >= 0)
		|| (m[1] > 0 && v->pl[1] - v->cm[1] > v->ss[1] / 2
			&& v->cm[1] + m[1] <= v->ms[1] - v->ss[1] - 1))
		v->cm[1] += m[1];
}
