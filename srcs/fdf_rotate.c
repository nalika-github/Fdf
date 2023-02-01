/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_iso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:30:36 by ptungbun          #+#    #+#             */
/*   Updated: 2023/01/27 13:50:59 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_rotate_z(t_map *map)
{
	double	buf[2];
	int		i;
	int		j;
	double	sint;
	double	cost;

	sint = sin(map->angle_z * PI / 180);
	cost = cos(map->angle_z * PI / 180);
	i = 0;
	while (i < map->n_row)
	{
		j = 0;
		while (j < map->n_col)
		{
			buf[0] = map->metrix[i][j].x * cost - map->metrix[i][j].y * sint;
			buf[1] = map->metrix[i][j].y * cost + map->metrix[i][j].x * sint;
			map->metrix[i][j].x = buf[0];
			map->metrix[i][j].y = buf[1];
			j++;
		}
		i++;
	}
}

void	fdf_rotate_x(t_map *map)
{
	double	buf[2];
	int		i;
	int		j;
	double	sint;
	double	cost;

	sint = sin(map->angle_x * PI / 180);
	cost = cos(map->angle_x * PI / 180);
	i = 0;
	while (i < map->n_row)
	{
		j = 0;
		while (j < map->n_col)
		{
			buf[0] = map->metrix[i][j].y * cost - map->metrix[i][j].z * sint;
			buf[1] = map->metrix[i][j].z * cost + map->metrix[i][j].y * sint;
			map->metrix[i][j].y = buf[0];
			map->metrix[i][j].z = buf[1];
			j++;
		}
		i++;
	}
}

void	fdf_rotate_y(t_map *map)
{
	double	buf[2];
	int		i;
	int		j;
	double	sint;
	double	cost;

	sint = sin(map->angle_y * PI / 180);
	cost = cos(map->angle_y * PI / 180);
	i = 0;
	while (i < map->n_row)
	{
		j = 0;
		while (j < map->n_col)
		{
			buf[0] = map->metrix[i][j].x * cost + map->metrix[i][j].z * sint;
			buf[1] = map->metrix[i][j].z * cost - map->metrix[i][j].x * sint;
			map->metrix[i][j].x = buf[0];
			map->metrix[i][j].z = buf[1];
			j++;
		}
		i++;
	}
}

void	fdf_rotate(t_map *map)
{
	fdf_rotate_z(map);
	fdf_rotate_x(map);
	fdf_rotate_y(map);
}
