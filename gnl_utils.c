/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <joaoribe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:14:04 by joaoribe          #+#    #+#             */
/*   Updated: 2024/01/14 01:47:26 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != 10)
		i++;
	if (s[i] == 10)
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*bf;
	size_t	i;

	bf = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!bf)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		bf[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		bf[i++] = *s2;
		if (*s2++ == 10)
			break ;
	}
	bf[i] = 0;
	return (bf);
}

int	nl(char *bf)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	j = 0;
	while (bf[i])
	{
		if (k == 1)
			bf[j++] = bf[i];
		if (bf[i] == 10)
			k = 1;
		bf[i++] = 0;
	}
	return (k);
}
