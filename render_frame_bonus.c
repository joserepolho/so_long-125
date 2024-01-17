/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:13:22 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/17 21:52:48 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_frame_bonus(t_vars *v)
{
	if (v->time == 0)
		v->time = clock();
	if (clock() - v->time >= CLOCKS_PER_SEC / 6)
	{
		v->f++;
		v->time = clock();
		render_frame(v);
	}
	return (0);
}
