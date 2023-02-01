/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptungbun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:08:11 by ptungbun          #+#    #+#             */
/*   Updated: 2023/01/27 14:08:15 by ptungbun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_deal_shift(int key, t_map *map)
{
	if (key == 65361)
		map->shift_x = map->shift_x - 10;
	if (key == 65363)
		map->shift_x = map->shift_x + 10;
	if (key == 65362)
		map->shift_y = map->shift_y - 10;
	if (key == 65364)
		map->shift_y = map->shift_y + 10;
	if (key == 105)
		map->scale = map->scale + 0.01 * map->scale;
	if (key == 111)
		map->scale = map->scale - 0.01 * map->scale;
	interac_shift(map);
}

void	fdf_deal_rotate(int key, t_map *map)
{
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	if (key == 97)
		map->angle_y = -1;
	if (key == 100)
		map->angle_y = 1;
	if (key == 115)
		map->angle_x = -1;
	if (key == 119)
		map->angle_x = 1;
	if (key == 113)
		map->angle_z = -1;
	if (key == 101)
		map->angle_z = 1;
	interac_rotate(map);
}

int	fdf_key_hook(int key, t_map *map)
{
	fdf_interac_filter(key, map);
	if (map->is_shift == 1)
		fdf_deal_shift(key, map);
	if (map->is_rotate == 1)
		fdf_deal_rotate(key, map);
	return (0);
}

int	fdf_esc_hook(int key, t_map *map)
{
	fdf_interac_filter(key, map);
	if (map->is_close == 1)
	{
		key = 0;
		interac_close(map);
	}
	return (0);
}
