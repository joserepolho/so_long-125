/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:17:21 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/17 02:44:59 by joaoribe         ###   ########.fr       */
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
	v.f = 0;
	mlx_key_hook(v.window, key_hook, &v);
	mlx_hook(v.window, 17, 1L << 17, free_all, &v);
	mlx_loop_hook(v.mlx, render_frame, &v);
	mlx_loop(v.mlx);
	return (0);
}
