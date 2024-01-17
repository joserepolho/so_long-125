/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:07:44 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/17 03:31:51 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_image_wc(t_vars *v, int *w, int *h)
{
	v->txt->wc = malloc(11 * sizeof(void *));
	if (!v->txt->wc)
	{
		perror("Error!\nTextures have failed to convert!\n");
		free_all(v);
	}
	v->txt->wc[10] = NULL;
	v->txt->wc[0] = mlx_xpm_file_to_image(v->mlx, "textures/wc0.xpm", w, h);
	v->txt->wc[1] = mlx_xpm_file_to_image(v->mlx, "textures/wc1.xpm", w, h);
	v->txt->wc[2] = mlx_xpm_file_to_image(v->mlx, "textures/wc2.xpm", w, h);
	v->txt->wc[3] = mlx_xpm_file_to_image(v->mlx, "textures/wc3.xpm", w, h);
	v->txt->wc[4] = mlx_xpm_file_to_image(v->mlx, "textures/wc4.xpm", w, h);
	v->txt->wc[5] = mlx_xpm_file_to_image(v->mlx, "textures/wc5.xpm", w, h);
	v->txt->wc[6] = mlx_xpm_file_to_image(v->mlx, "textures/wc6.xpm", w, h);
	v->txt->wc[7] = mlx_xpm_file_to_image(v->mlx, "textures/wc7.xpm", w, h);
	v->txt->wc[8] = mlx_xpm_file_to_image(v->mlx, "textures/wc8.xpm", w, h);
	v->txt->wc[9] = mlx_xpm_file_to_image(v->mlx, "textures/wc9.xpm", w, h);
}

void	xpm_to_image_c(t_vars *v, int *w, int *h)
{
	v->txt->c = malloc(9 * sizeof(void *));
	if (!v->txt->c)
	{
		perror("Error!\nTextures have failed to convert!\n");
		free_all(v);
	}
	v->txt->c[7] = '\0';
	v->txt->c[0] = mlx_xpm_file_to_image(v->mlx, "textures/c1.xpm", w, h);
	v->txt->c[1] = mlx_xpm_file_to_image(v->mlx, "textures/c2.xpm", w, h);
	v->txt->c[2] = mlx_xpm_file_to_image(v->mlx, "textures/c3.xpm", w, h);
	v->txt->c[3] = mlx_xpm_file_to_image(v->mlx, "textures/c4.xpm", w, h);
	v->txt->c[4] = v->txt->c[2];
	v->txt->c[5] = v->txt->c[1];
	v->txt->c[6] = v->txt->c[0];
}

void	get_textures(t_vars *v)
{
	int	w;
	int	h;

	v->txt = malloc(sizeof(t_tx));
	if (!(v->txt))
	{
		perror("Error!\nTextures have failed to convert!\n");
		free_all(v);
	}
	v->txt->p = mlx_xpm_file_to_image(v->mlx, "textures/p.xpm", &w, &h);
	v->txt->w = mlx_xpm_file_to_image(v->mlx, "textures/w.xpm", &w, &h);
	xpm_to_image_wc(v, &w, &h);
	v->txt->fl = mlx_xpm_file_to_image(v->mlx, "textures/fl.xpm", &w, &h);
	xpm_to_image_c(v, &w, &h);
	v->txt->eo = mlx_xpm_file_to_image(v->mlx, "textures/eo.xpm", &w, &h);
	v->txt->ec = mlx_xpm_file_to_image(v->mlx, "textures/ec.xpm", &w, &h);
	v->txt->ecm = mlx_xpm_file_to_image(v->mlx, "textures/ecm.xpm", &w, &h);
	v->txt->en = mlx_xpm_file_to_image(v->mlx, "textures/en.xpm", &w, &h);
}
