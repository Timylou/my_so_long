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

static void	ft_switch_camera(char block, int x, int y, t_game *game)
{
	if (block == 'A')
		ft_star_animation(game, x, y);
	x = x * 64 - game->cam_x;
	y = y * 64 - game->cam_y;
	if (block == '1')
		ft_put_image_clean(game->platforms[0], x, y, game->frame);
	else if (block == '4')
		ft_put_image_clean(game->platforms[1], x, y, game->frame);
	else if (block == '3')
		ft_put_image_clean(game->platforms[2], x, y, game->frame);
	else if (block == '2')
		ft_put_image_clean(game->platforms[3], x - 64, y, game->frame);	
	else if (block == '7')
		ft_put_image_clean(game->platforms[4], x - 64, y, game->frame);	
	else if (block == '6')
		ft_put_image_clean(game->platforms[5], x - 64, y, game->frame);	
	else if (block == '5')
		ft_put_image_clean(game->platforms[6], x - 64, y, game->frame);	
	else if (!game->coins && block == 'E')
		ft_exit_animation(game, x, y);
	else if (block == 'C')
		ft_apple_animation(game, x, y);
}

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
			if (0 <= y && y <= game->m_height && 0 <= x && x <= game->m_width)
				ft_switch_camera(game->map[y][x], x, y, game);
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
