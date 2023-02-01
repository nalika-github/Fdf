/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:41:54 by ptungbun          #+#    #+#             */
/*   Updated: 2022/12/26 14:41:56 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_getmax(t_map *map, double *max)
{
	int	i;
	int	j;

	i = 0;
	max[0] = map->metrix[0][0].x;
	max[1] = map->metrix[0][0].y;
	while (i < map->n_row)
	{
		j = 0;
		while (j < map->n_col)
		{
			if (max[0] < map->metrix[i][j].x)
				max[0] = map->metrix[i][j].x;
			if (max[1] < map->metrix[i][j].y)
				max[1] = map->metrix[i][j].y;
			j++;
		}
		i++;
	}
}

void	fdf_getmin(t_map *map, double *min)
{
	int	i;
	int	j;

	i = 0;
	min[0] = map->metrix[0][0].x;
	min[1] = map->metrix[0][0].y;
	while (i < map->n_row)
	{
		j = 0;
		while (j < map->n_col)
		{
			if (min[0] > map->metrix[i][j].x)
				min[0] = map->metrix[i][j].x;
			if (min[1] > map->metrix[i][j].y)
				min[1] = map->metrix[i][j].y;
			j++;
		}
		i++;
	}
}

double	default_scale(double *max, double *min)
{
	double	width;
	double	height;
	double	scale;
	double	buf;

	width = max[0] - min[0];
	height = max[1] - min[1];
	scale = 0.95 * (WINDOW_WIDTH / width);
	buf = 0.95 * (WINDOW_HEIGHT / height);
	if (buf < scale)
		scale = buf;
	return (scale);
}

void	fdf_set_default(t_map *map)
{
	double	max[2];
	double	min[2];

	map->is_close = 0;
	map->is_rotate = 0;
	map->is_shift = 0;
	fdf_set_center(map);
	map->angle_x = 45;
	map->angle_y = 0;
	map->angle_z = 45;
	fdf_rotate(map);
	fdf_getmax(map, max);
	fdf_getmin(map, min);
	map->scale = default_scale(max, min);
	map->shift_x = WINDOW_WIDTH / 2;
	map->shift_y = WINDOW_HEIGHT / 2;
}
