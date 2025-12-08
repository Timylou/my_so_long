/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:58:50 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/08 14:58:51 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*ft_init_tile(int tile_size, t_game *game)
{
	t_img	*tile;

	tile = malloc(sizeof(t_img));
	if (!tile)
		ft_error("Malloc tile\n", game);
	tile->img = mlx_new_image(game->mlx, tile_size, tile_size);
	if (!tile->img)
	{
		free(tile);
		ft_error("tile image init\n", game);
	}
	tile->data = mlx_get_data_addr(tile->img,
			&tile->bpp, &tile->size_line, &tile->edn);
	tile->width = tile_size;
	tile->height = tile_size;
	return (tile);
}

t_img	*ft_get_tile(t_img *tileset, int tile_size, int tile_num, t_game *game)
{
	t_img	*tile;
	int		offsets[2];
	int		color;
	int		x;
	int		y;

	tile = ft_init_tile(tile_size, game);
	offsets[0] = (tile_num % (tileset->width / tile_size)) * tile_size;
	offsets[1] = (tile_num / (tileset->width / tile_size)) * tile_size;
	y = 0;
	while (y < tile_size)
	{
		x = 0;
		while (x < tile_size)
		{
			color = ft_get_pixel(tileset, x + offsets[0], y + offsets[1]);
			ft_put_pixel(tile, x, y, color);
			x++;
		}
		y++;
	}
	return (tile);
}
