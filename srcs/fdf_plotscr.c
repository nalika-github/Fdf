/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_plotscr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:36:19 by ptungbun          #+#    #+#             */
/*   Updated: 2023/01/27 15:03:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_scr	**scr_alloc(int n_col, int n_row)
{
	t_scr	**scr;
	int		i;

	scr = (t_scr **)malloc(sizeof(t_scr *) * n_row);
	i = 0;
	while (i < n_row)
	{
		scr[i] = (t_scr *)malloc(sizeof(t_scr) * n_col);
		i++;
	}
	return (scr);
}

t_scr	**fdf_plotscr(t_map *map)
{
	int		i;
	int		j;
	t_scr	**scr;
	t_coor	**met;

	scr = scr_alloc(map->n_col, map->n_row);
	met = map->metrix;
	i = 0;
	while (i < map->n_row)
	{
		j = 0;
		while (j < map->n_col)
		{
			scr[i][j].x = (int)(met[i][j].x * map->scale) + map->shift_x;
			scr[i][j].y = (int)(met[i][j].y * map->scale) + map->shift_y;
			scr[i][j].color = map->metrix[i][j].color;
			j++;
		}
		i++;
	}
	return (scr);
}
