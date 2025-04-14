/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:29:33 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/24 13:18:00 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_player_images(t_player *player, t_game *game)
{
	int	size[2];

	size[0] = 64;
	size[1] = 64;
	player->img_up = ft_open_image(game->mlx, "img/p_up.xpm", size);
	player->img_down = ft_open_image(game->mlx, "img/p_down.xpm", size);
	player->img_right = ft_open_image(game->mlx, "img/p_right.xpm", size);
	player->img_left = ft_open_image(game->mlx, "img/p_left.xpm", size);
	if (!player->img_up || !player->img_down || !player->img_right
		|| !player->img_left)
		ft_error("Cannot load player image", game);
}

static void	ft_check_mouvement(t_player *player, t_map *map, t_game *game)
{
	int	x;
	int	y;
	
	x = player->x;
	y = player->y;
	if (map->map[y][x] == EXIT && player->coins == game->coins)
		ft_win(game);
	if (map->map[y][x] == COIN)
	{
		player->coins += 1;
		map->map[y][x] = EMPTY;
	}
}

void	ft_player_mouvement(t_player *player, t_game *game, t_direction dir)
{
	t_map	*map;
	int		x;
	int		y;
	
	x = player->x;
	y = player->y;
	player->dir = dir;
	if (dir == UP)
		y--;
	if (dir == DOWN)
		y++;
	if (dir == RIGHT)
		x++;
	if (dir == LEFT)
		x--;
	map = game->map;
	if (x > 0 && x < map->width && y > 0 && y < map->height
			&& map->map[y][x] != WALL)
	{
		player->x = x;
		player->y = y;
		game->steps += 1;
		ft_print_steps(game->steps);
	}
	ft_check_mouvement(player, map, game);
}

void	ft_init_player(t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	game->player = player;
	if (!player)
		ft_error("malloc error player", game);
	player->x = 0;
	player->y = 0;
	player->coins = 0;
	player->dir = DOWN;
	ft_player_images(player, game);
}
