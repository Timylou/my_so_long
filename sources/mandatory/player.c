/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 19:11:05 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/04 19:11:08 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_player(t_game *game)
{
	if (!game->player)
		return ;
	free(game->player);
}

void	ft_init_player_images(t_player *player, t_game *game)
{
	t_img	*tileset;

	tileset = ft_open_image(game->mlx, "textures/player.xpm", 512, 576);
	if (!tileset)
		ft_error("tileset image init\n", game);
	player->idle[0] = ft_get_tile(tileset, 64, 0, game);
	player->idle[1] = ft_get_tile(tileset, 64, 1, game);
	player->walk[0] = ft_get_tile(tileset, 64, 16, game);
	player->walk[1] = ft_get_tile(tileset, 64, 17, game);
	player->walk[2] = ft_get_tile(tileset, 64, 18, game);
	player->walk[3] = ft_get_tile(tileset, 64, 19, game);
	ft_free_image(tileset, game);
}

void	ft_set_pos_player(t_game *game, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
	game->cam_x = x * 64;
	if (game->cam_x < 0)
		game->cam_x = 0;
	if (game->cam_x >= game->w_width)
		game->cam_x = game->w_width - 64;
	game->cam_y = y * 64;
	if (game->cam_y < 0)
		game->cam_y = 0;
	if (game->cam_y >= game->w_height)
		game->cam_y = game->w_height - 64;
}
