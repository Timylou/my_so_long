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

void	ft_init_player_images(t_player *player, t_game *game, int i)
{
	t_img	*tileset;

	tileset = ft_open_image(game->mlx, "textures/player.xpm", 512, 576);
	if (!tileset)
		ft_error("tileset image init\n", game);
	while (++i < 8)
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
		if (i < 8)
			player->jump[i] = ft_get_tile(tileset, 64, 40 + i, game);
		if (i < 8)
			player->jump[8 + i] = flip_xpm_horizontally(player->jump[i], game);
	}
	ft_free_image(tileset, game);
}

void	ft_set_pos_player(t_game *game, int x, int y)
{
	game->player->x = x;
	game->player->y = y;
	game->cam_x = (x * 64) - (10 * 64);
	game->cam_y = (y * 64) - (5 * 64);
	if (game->player->x < 10)
		game->cam_x = 0;
	if (game->player->x > game->m_width - 20)
		game->cam_x = (game->m_width - 30) * 64;
	if (game->map[y + 1][x] != '1')
	{
		game->player->key_jump = 0;
		game->player->velocity = 0;
	}
}

static void	ft_mouvement(t_game *game, float new_x, float new_y, float dt)
{
	game->player->x = new_x;
	if (game->map[(int)new_y][(int)(new_x)] == 'C')
	{
		game->map[(int)new_y][(int)new_x] = 'A';
		game->coins -= 1;
	}
	if (!game->player->key_jump
		&& game->map[(int)(new_y + 1)][(int)new_x] != '1')
	{
		game->player->velocity = -0.1;
		game->player->key_jump = 1;
		ft_jump(game, dt);
	}
}

void	ft_move_player(t_game *game, float dt)
{
	float	new_x;
	float	new_y;
	float	speed;

	speed = 0;
	if (game->player->key_left || game->player->key_right)
		speed = 0.05;
	if (game->player->key_run)
		speed = 0.1;
	new_x = 0;
	new_y = ft_jump(game, dt);
	game->player->y = new_y;
	if (!game->player->key_left && !game->player->key_right
		&& !game->player->key_jump)
		return ;
	if (game->player->key_left)
		new_x = game->player->x - speed;
	if (game->player->key_right)
		new_x = game->player->x + speed;
	if (ft_check_mouvement(game->map[(int)new_y][(int)(new_x)]))
		ft_mouvement(game, new_x, new_y, dt);
	else
		speed = 0;
	ft_move_camera(game, speed);
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
	if (player->key_jump)
		ft_jump_animation(game, look_left);
	else if ((player->key_left || player->key_right) && player->key_run)
		ft_run_animation(game, look_left, time);
	else if (player->key_left || player->key_right)
		ft_walk_animation(game, look_left, time);
	else
		ft_idle_animation(game, look_left, time);
}
