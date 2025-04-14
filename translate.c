/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:07:32 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/26 14:54:45 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_case	ft_switch(char tile, int *player, int *exit, t_game *game)
{
	if (tile == '0')
		return (EMPTY);
	if (tile == '1')
		return (WALL);
	if (tile == 'C')
		return (COIN);
	/* if (tile == 'E')
	{
		(*exit)++;
		if (*exit > 1)
			ft_error("too much exits", game);
		return (EXIT);
	}
	if (tile == 'P')
	{
		(*player)++;
		if (*player > 1)
			ft_error("too much players", game);
		return (PLAYER);
	} */
	if (tile == 'P' || tile == 'E' || tile == 'C')
		(*player)++;
		if (*player > 1)
			ft_error("too much players", game);
		return (PLAYER);
	ft_error("Invalid Map", game);
	return (EMPTY);
}

static void	ft_alloc_map(t_map *map, t_game *game)
{
	int	i;

	map->map = malloc(sizeof(t_case *) * map->height);
	if (!map->map)
		ft_error("malloc map error", game);
	i = 0;
	while (i < map->height)
	{
		map->map[i] = malloc(sizeof(t_case) * map->width);
		if (!map->map[i])
		{
			while (--i <= 0)
				free(map->map[i]);
			free(map->map);
			map->map = NULL;
			ft_error("malloc map error", game);
		}
		i++;
	}
}

static void	ft_browse_map(t_map *map, t_game *game)
{
	char	cur_tile;
	int		player;
	int		exit;
	int		i;
	int		j;

	player = 0;
	exit = 0;
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (map->temp_map[j][i] && map->temp_map[j][i] != '\n')
		{
			if (i > map->width)
				ft_error("Invalid map", game);
			cur_tile = map->temp_map[j][i];
			map->map[j][i] = ft_switch(cur_tile, &player, &exit, game);
			i++;
		}
		j++;
	}
	if (!player || !exit)
		ft_error("Must have at least 1 player and 1 exit", game);
}

void	ft_translate_map(t_map *map, t_game *game)
{
	if (map->height < 4 || map->width < 4)
		ft_error("map too short", game);
	ft_alloc_map(map, game);
	ft_browse_map(map, game);
}
