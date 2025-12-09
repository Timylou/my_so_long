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
	int		i;

	tileset = ft_open_image(game->mlx, "textures/player.xpm", 512, 576);
	if (!tileset)
		ft_error("tileset image init\n", game);
	i = 0;
	while (i < 8)
	{
		if (i < 2)
			player->idle[i] = ft_get_tile(tileset, 64, i, game);
		if (i < 2)
			player->idle[2 + i] = flip_xpm_horizontally(player->idle[i], game);
		if (i < 4)
			player->walk[i] = ft_get_tile(tileset, 64, 16 + i, game);
		if (i < 4)
			player->walk[4 + i] = flip_xpm_horizontally(player->walk[i], game);
		if (i < 8)
			player->run[i] = ft_get_tile(tileset, 64, 24 + i, game);
		if (i < 8)
			player->run[8 + i] = flip_xpm_horizontally(player->run[i], game);
		i++;
	}
	ft_free_image(tileset, game);
}

void	ft_set_pos_player(t_game *game, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
	game->cam_x = x * 64 - 5 * 64;
	if (game->cam_x < 0)
		game->cam_x = 0;
	if (game->cam_x >= game->w_width)
		game->cam_x = game->w_width - 64;
	game->cam_y = y * 64 - 5 * 64;
	if (game->cam_y < 0)
		game->cam_y = 0;
	if (game->cam_y >= game->w_height)
		game->cam_y = game->w_height - 64;
}

void	ft_move_player(t_game *game)
{
	float	new_x;
	float	new_y;
	float	speed;

	speed = 0.05;
	if (game->player->key_run)
		speed = 0.1;
	new_x = 0;
	new_y = game->player->y;
	if (!game->player->key_left && !game->player->key_right)
		return ;
	if (game->player->key_left)
		new_x = game->player->x - speed;
	if (game->player->key_right)
		new_x = game->player->x + speed;
	if (game->map[(int)new_y][(int)new_x] != '1')
	{
		game->player->x = new_x;
		ft_move_camera(game, speed);
	}
}

void	ft_draw_player(t_game *game, long time)
{
	static int		look_left = 0;
	t_player		*player;

	player = game->player;
	if (player->key_right)
		look_left = 0;
	if (player->key_left || (look_left && !player->key_right))
		look_left = 1;
	if ((player->key_left || player->key_right) && player->key_run)
		ft_run_animation(game, look_left, time);
	else if (player->key_left || player->key_right)
		ft_walk_animation(game, look_left, time);
	else
		ft_idle_animation(game, look_left, time);
}
