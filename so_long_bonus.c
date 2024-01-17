/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:12:09 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/17 02:13:21 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_vars	v;

	if (ac != 2)
		ft_error_beginning("Error\n 1 argument only required!\n");
	mapping(&v, av);
	v.mlx = mlx_init();
	i = v.ms[1];
	j = v.ms[0];
	init_center_of_mass(&v);
	v.window = mlx_new_window(v.mlx, (i - 1) * 64, j * 64, "so_long");
	get_textures(&v);
	v.move = 0;
	v.time = 0;
	v.f = 1;
	mlx_key_hook(v.window, key_hook, &v);
	render_frame(&v);
	mlx_hook(v.window, 17, 1L << 17, free_all, &v);
	mlx_loop_hook(v.mlx, render_frame_bonus, &v);
	mlx_loop(v.mlx);
	return (0);
}
