/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:37:34 by ptungbun          #+#    #+#             */
/*   Updated: 2023/01/11 17:37:35 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	find_center(t_map *map, double *center)
{
	double	max[2];
	double	min[2];

	max[0] = 1;
	fdf_getmax(map, max);
	fdf_getmin(map, min);
	center[0] = (max[0] - min[0]) / 2;
	center[1] = (max[1] - min[1]) / 2;
}

void	fdf_set_center(t_map *map)
{
	double	cp[2];
	int		i;
	int		j;

	find_center(map, cp);
	cp[0] = -1 * cp[0];
	cp[1] = -1 * cp[1];
	i = 0;
	while (i < map->n_row)
	{
		j = 0;
		while (j < map->n_col)
		{
			map->metrix[i][j].x = map->metrix[i][j].x + cp[0];
			map->metrix[i][j].y = map->metrix[i][j].y + cp[1];
			j++;
		}
		i++;
	}
}
