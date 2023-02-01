/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:38:16 by ptungbun          #+#    #+#             */
/*   Updated: 2023/01/27 13:52:13 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_render_x(t_map *map, t_scr **scr, t_image *img)
{
	int	i;
	int	j;
	int	x[2];
	int	y[2];

	i = 0;
	while (i < map->n_row)
	{
		j = 0;
		while (j < map->n_col - 1)
		{
			x[0] = scr[i][j].x;
			y[0] = scr[i][j].y;
			x[1] = scr[i][j + 1].x;
			y[1] = scr[i][j + 1].y;
			fdf_drawline(&(*img), x, y, scr[i][j].color);
			j++;
		}
		i++;
	}
}

void	fdf_render_y(t_map *map, t_scr **scr, t_image *img)
{
	int	i;
	int	j;
	int	x[2];
	int	y[2];

	i = 0;
	while (i < map->n_row - 1)
	{
		j = 0;
		while (j < map->n_col)
		{
			x[0] = scr[i][j].x;
			y[0] = scr[i][j].y;
			x[1] = scr[i + 1][j].x;
			y[1] = scr[i + 1][j].y;
			fdf_drawline(&(*img), x, y, scr[i][j].color);
			j++;
		}
		i++;
	}
}

void	fdf_render(t_map *map, t_scr **scr, t_image *img)
{
	fdf_render_x(map, scr, img);
	fdf_render_y(map, scr, img);
}
