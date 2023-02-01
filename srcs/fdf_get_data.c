/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:01:37 by ptungbun          #+#    #+#             */
/*   Updated: 2023/01/14 12:01:39 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_color(char **box)
{
	int	i;

	i = 0;
	while (box[i])
		i++;
	if (i == 2)
		return (1);
	return (0);
}

int	get_color(char *hex)
{
	int		i;
	int		j;
	int		color;
	char	*hextext;

	i = 0;
	color = 0;
	while (hex[i])
	{
		hex[i] = (char)ft_tolower(hex[i]);
		i++;
	}
	i--;
	hextext = "0123456789abcdef";
	while (i >= 2)
	{
		j = 0;
		while (hextext[j] != hex[i])
			j++;
		color = color + j * pow(16, -1 * (i - 7));
		i--;
	}
	return (color);
}

void	fdf_get_data(t_map *map, char **box, int i, int j)
{
	t_coor	**metrix;

	metrix = map->metrix;
	if (check_color(box))
	{
		metrix[i][j].z = ft_atoi(box[0]);
		metrix[i][j].color = get_color(box[1]);
		free(box[0]);
		free(box[1]);
	}
	else
	{
		metrix[i][j].color = 0xffffff;
		metrix[i][j].z = ft_atoi(box[0]);
		free(box[0]);
	}
}
