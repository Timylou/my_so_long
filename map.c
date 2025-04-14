/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:23:16 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/24 13:22:09 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game_images(t_game *game)
{
	int		size[2];

	size[0] = 64;
	size[1] = 64;
	game->ground = NULL;
	game->img_coin = NULL;
	game->wall = NULL;
	game->exit = NULL;
	game->ground = ft_open_image(game->mlx, "img/ground.xpm", size);
	if (!game->ground)
		ft_error("Background Init", game);
	game->img_coin = ft_open_image(game->mlx, "img/coin.xpm", size);
	if (!game->img_coin)
		ft_error("Img coin Init", game);
	game->wall = ft_open_image(game->mlx, "img/wall.xpm", size);
	if (!game->wall)
		ft_error("Wall Init", game);
	game->exit = ft_open_image(game->mlx, "img/exit.xpm", size);
	if (!game->exit)
		ft_error("Exit Init", game);
}

static void ft_display_player(t_player *player, t_game *game)
{
	int	x;
	int	y;

	x = player->x;
	y = player->y;
	if (player->dir == UP)
		ft_put_image(player->img_up, x * 64, y * 64, game->buffer);
	else if (player->dir == DOWN)
		ft_put_image(player->img_down, x * 64, y * 64, game->buffer);
	else if (player->dir == RIGHT)
		ft_put_image(player->img_right, x * 64, y * 64, game->buffer);
	else if (player->dir == LEFT)
		ft_put_image(player->img_left, x * 64, y * 64, game->buffer);
}

static void	ft_display_exit(t_game *game, int x, int y)
{
	ft_put_image(game->ground, x * 64, y * 64, game->buffer);
	if (game->player->coins == game->coins)
		ft_put_image(game->exit, x * 64, y * 64, game->buffer);
}

void	ft_map_to_buffer(t_game *game)
{
	t_map	*map;
	int		x;
	int		y;

	map = game->map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == WALL)
				ft_put_image(game->wall, x * 64, y * 64, game->buffer);
			else if (map->map[y][x] == EXIT)
				ft_display_exit(game, x, y);
			else if (map->map[y][x] == EMPTY || map->map[y][x] == COIN)
				ft_put_image(game->ground, x * 64, y * 64, game->buffer);
			if (map->map[y][x] == COIN)
				ft_put_image(game->img_coin, x * 64, y * 64, game->buffer);
			x++;
		}
		y++;
	}
	ft_display_player(game->player, game);
}
