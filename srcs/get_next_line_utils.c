/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 12:20:12 by ptungbun          #+#    #+#             */
/*   Updated: 2023/02/01 10:35:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	ft_gnlisn_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_gnlline_len(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

size_t	ft_gnlstrlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void	*ft_gnlcalloc(size_t nmemb, size_t size)
{
	void			*room;
	size_t			i;
	unsigned char	*buf;

	room = (void *)malloc(nmemb * size);
	if (!room)
		return (0);
	i = 0;
	buf = (unsigned char *)room;
	while (i < (nmemb * size))
	{
		buf[i] = '\0';
		i++;
	}
	room = buf;
	return (room);
}

char	*ft_gnlstrcat(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*buf;

	buf = malloc(sizeof(char) * (ft_gnlstrlen(s1) + ft_gnlstrlen(s2) + 1));
	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
	{
		buf[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		buf[i + j] = s2[j];
		j++;
	}
	buf[i + j] = '\0';
	free(s1);
	return (buf);
}
