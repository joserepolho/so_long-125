/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:47:26 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/14 02:08:17 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	bf[BUFFER_SIZE + 1];
	char		*ln;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		ft_memset(bf, '\0', BUFFER_SIZE + 1);
		return (0);
	}
	ln = 0;
	while (*bf || read(fd, bf, BUFFER_SIZE) > 0)
	{
		ln = ft_strjoin(ln, bf);
		if (nl(bf) == 1)
			break ;
	}
	return (ln);
}
