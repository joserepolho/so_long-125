/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:47:51 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/17 21:54:22 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_num(int n)
{
	char	c;

	if (n >= 10)
		write_num(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	move(t_vars *v, int *m)
{
	if ((m[0] > 0 && v->map[v->pl[0] + m[0]][v->pl[1] + m[1]] != '1')
		|| (m[0] < 0 && v->map[v->pl[0] + m[0]][v->pl[1]] != '1'))
	{
		v->pl[0] += m[0];
		v->move++;
	}
	if ((m[1] > 0 && v->map[v->pl[0]][v->pl[1] + m[1]] != '1')
		|| (m[1] < 0 && v->map[v->pl[0]][v->pl[1] + m[1]] != '1'))
	{
		v->pl[1] += m[1];
		v->move++;
	}
	if (v->map[v->pl[0]][v->pl[1]] == 'C')
	{
		v->map[v->pl[0]][v->pl[1]] = '0';
		v->coll--;
	}
	if (v->map[v->pl[0]][v->pl[1]] == 'G')
		free_all(v);
	if (v->map[v->pl[0]][v->pl[1]] == 'E' && v->coll == 0)
		free_all(v);
	check_center_of_mass(v, m);
}

int	key_hook(int keycode, t_vars *v)
{
	int	m[2];

	if (keycode == 65307)
		free_all(v);
	m[0] = (keycode == 115) - (keycode == 119);
	m[1] = (keycode == 100) - (keycode == 97);
	if (m[0] || m[1])
	{
		move(v, m);
		write(1, "Number of moves: ", 17);
		write_num(v->move);
		write(1, "\n", 1);
	}
	return (0);
}
