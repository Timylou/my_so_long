/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:33:38 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/10 13:33:39 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_map(t_game *game)
{
	char	**map;
	int		y;
	int		x;
	int		width;

	map = game->map;
	width = game->m_width;
	y = -1;
	while (++y < game->m_height)
	{
		x = -1;
		while (++x < width)
		{
			if (y < 4 && (x == 0 || x == width - 1))
				map[y][x] = '2' + 3 * (x > 0);
			else if (y == 0)
				map[y][x] = '0';
			else if (y == game->m_height - 1 && (x == 0 || x == width - 1))
				map[y][x] = '1';
			else if (y == game->m_height - 2 && (x == 0 || x == width - 1))
				map[y][x] = '4' + 3 * (x > 0);
			else if (x == 0 || x == width - 1)
				map[y][x] = '3' + 3 * (x > 0);
		}
	}
}
