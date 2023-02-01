/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:22:54 by ptungbun          #+#    #+#             */
/*   Updated: 2023/01/27 15:04:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_cleanup(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_row)
	{
		free(map->metrix[i]);
		free(map->scr[i]);
		i++;
	}
	free(map->metrix);
	free(map->scr);
}
