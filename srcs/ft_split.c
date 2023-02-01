/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 08:51:51 by ptungbun          #+#    #+#             */
/*   Updated: 2023/02/01 10:34:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static size_t	cell_count(char const *s, char c)
{
	size_t	touch;
	size_t	n;
	size_t	i;

	touch = 0;
	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (touch == 0 && s[i] != c)
		{
			n++;
			touch = 1;
		}
		else if (s[i] == c)
			touch = 0;
		i++;
	}
	return (n);
}

static	size_t	sub_strlen(char const *s, size_t index, char c)
{
	size_t	i;

	i = 0;
	while (s[index + i] != c && s[index + i] != '\0')
		i++;
	return (i);
}

static char	*cell_input(char const *s, size_t index, char c, char *cell)
{
	size_t	i;

	i = 0;
	while (s[index + i] != c && s[index + i] != 0)
	{
		cell[i] = s[index + i];
		i++;
	}
	cell[i] = 0;
	return (cell);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	sub_len;
	char	**split;

	split = malloc(sizeof(char *) * (cell_count(s, c) + 1));
	split[cell_count(s, c)] = 0;
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			sub_len = sub_strlen(s, i, c);
			split[j] = malloc(sizeof(char) * sub_len + 1);
			split[j] = cell_input(s, i, c, split[j]);
			i = i + sub_len - 1;
			j++;
		}
		i++;
	}
	return (split);
}
