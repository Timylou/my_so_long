/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:38:24 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/25 15:03:11 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rec_flood_fill(char **map, int x, int y, int *flag)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'E' || map[y][x] == 'C')
		*flag += 1;
	map[y][x] = 'X';
	rec_flood_fill(map, x, y - 1, flag);
	rec_flood_fill(map, x, y + 1, flag);
	rec_flood_fill(map, x + 1, y, flag);
	rec_flood_fill(map, x - 1, y, flag);
}

void	ft_flood_fill(t_game *game)
{
	char	**map;
	int		flag;

	flag = 0;
	map = game->map->temp_map;
	rec_flood_fill(map, game->player->x, game->player->y, &flag);
	if (flag != game->coins + 1)
		ft_error("Error\nMap not winnable", game);
}
