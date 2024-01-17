/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:19:16 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/17 03:20:03 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>

# define BUFFER_SIZE 512

typedef struct s_tx
{
	void	*p;
	void	*w;
	void	**wc;
	void	*fl;
	void	**c;
	void	*eo;
	void	*ec;
	void	*ecm;
	void	*eom;
	void	*en;
}	t_tx;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	char	**map;
	int		pl[2];
	int		ms[2];
	int		ss[2];
	int		cm[2];
	int		coll;
	int		move;
	int		k;
	t_tx	*txt;
	int		f;
	clock_t	time;
	int		i;
}	t_vars;

void	mapping(t_vars *v, char **av);
char	*get_next_line(int fd);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int		nl(char *bf);
void	check_map(t_vars *v);
int		ft_strlen(const char *s);
void	check_components(t_vars *v);
void	player_pos(char **map, int *start);
void	check_path(t_vars *v);
char	**clone_map(t_vars *v);
void	flood_fill(char **map, int y, int x);
void	init_center_of_mass(t_vars *v);
void	check_center_of_mass(t_vars *v, int *m);
void	get_textures(t_vars *v);
int		key_hook(int keycode, t_vars *v);
int		free_all(t_vars *v);
void	move(t_vars *v, int *m);
int		render_frame(t_vars *v);
void	texture_render(t_vars *v, void *txt, int y, int x);
void	render_player(t_vars *v);
int		move_counter(t_vars *v);
void	ft_error(t_vars *v, char *err_type);
void	ft_error_beginning(char *err);
void	free_mlx(t_vars *v);
void	free_map(char **map);
void	checks_error(char **map, char *err);
int		render_frame_bonus(t_vars *v);

#endif
