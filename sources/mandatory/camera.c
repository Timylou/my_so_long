/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:45:10 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/09 12:45:11 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_loop_camera(t_game *game, int end_tile_x, int end_tile_y, int y)
{
	int	start_x;
	int	x;

	start_x = game->cam_x / 64;
	while (y <= end_tile_y)
	{
		x = start_x;
		while (x <= end_tile_x)
		{
			if (game->map[y][x] == '1')
				ft_put_image_clean(game->platforms[0], x * 64 - game->cam_x,
					y * 64 - game->cam_y, game->frame);
			if (game->map[y][x] == 'E')
				ft_exit_animation(game, x * 64 - game->cam_x, y * 64 - game->cam_y);
			x++;
		}
		y++;
	}
}

void	ft_draw_platforms(t_game *game)
{
	int	y;
	int	end_tile_x;
	int	end_tile_y;

	y = game->cam_y / 64 - 1;
	end_tile_x = (game->cam_x + game->w_width) / 64;
	end_tile_y = (game->cam_y + game->w_height) / 64;
	if (end_tile_x >= game->m_width)
		end_tile_x = game->m_width - 1;
	if (end_tile_y >= game->m_height)
		end_tile_y = game->m_height - 1;
	ft_loop_camera(game, end_tile_x, end_tile_y, y);
}

void	ft_move_camera(t_game *game, float speed)
{
	if (game->player->key_right)
		ft_travelling_left(game);
	if (game->player->key_left)
		ft_travelling_right(game);
	if (game->player->key_right && game->player->x > 10
		&& game->player->x < (float)(game->m_width - 20))
		game->cam_x += speed * 64;
	if (game->player->key_left && game->player->x < game->m_width - 20)
		game->cam_x -= speed * 64;
	if (game->player->x < 10)
		game->cam_x = 0;
	if (game->player->x > game->m_width - 20)
		game->cam_x = (game->m_width - 30) * 64;
}
