/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_before_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:46:57 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/15 18:43:16 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checks_error(char **map, char *err)
{
	perror(err);
	free_map(map);
	exit(1);
}

void	free_mlx(t_vars *v)
{
	if (v->mlx)
	{
		if (v->window)
			mlx_destroy_window(v->mlx, v->window);
		mlx_destroy_display(v->mlx);
		free(v->mlx);
	}
}
