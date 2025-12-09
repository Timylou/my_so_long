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

static void	ft_put_pixel_clean(t_img *img, int x, int y, int color)
{
	char			*dst;
	int				pos;
	long int		size;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return;
	size = img->size_line * img->height;
	pos = ((y * img->size_line) + (x * (img->bpp / 8)));
	if (pos < 0)
		pos += size;
	if (pos > size)
		pos = pos % size;
	dst = img->data + pos;
	*(unsigned int *)dst = color;
}

static void	ft_put_image_clean(t_img *img, int x_off, int y_off, t_img *buff)
{
	int	x;
	int	y;
	int	color;

	if (!buff || !img)
		return ;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color = ft_get_pixel(img, x, y);
			if (color >= 0)
				ft_put_pixel_clean(buff, x + x_off, y + y_off, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_in_camera(t_game *game)
{
	int start_tile_x = game->cam_x / 64;
	int start_tile_y = game->cam_y / 64;

	int end_tile_x = (game->cam_x + game->w_width) / 64;
	int end_tile_y = (game->cam_y + game->w_height) / 64;

	if (start_tile_x < 0) start_tile_x = 0;
	if (start_tile_y < 0) start_tile_y = 0;

	if (end_tile_x >= game->m_width)  end_tile_x = game->m_width - 1;
	if (end_tile_y >= game->m_height) end_tile_y = game->m_height - 1;

	for (int y = start_tile_y; y <= end_tile_y; y++)
	{
		for (int x = start_tile_x; x <= end_tile_x; x++)
		{
			char tile = game->map[y][x];

			// Convert tile position to screen pixels
			float screen_x = x * 64 - game->cam_x;
			float screen_y = y * 64 - game->cam_y;

			// Draw depending on tile type
			if (tile == '1')
				ft_put_image_clean(game->platforms[0], screen_x, screen_y, game->frame);
		}
	}
}
