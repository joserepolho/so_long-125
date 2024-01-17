/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:35:16 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/15 18:21:46 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(char **map, int *start)
{
	int	i;
	int	j;

	i = 0;
	while (map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				start[0] = i;
				start[1] = j;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
