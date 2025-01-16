/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:56:24 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/16 10:36:30 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_platform(t_game *game)
{
	t_img	**platform;
	t_img	*src;
	int		size[2];
	int		coor[2];
	int		i;

	platform = malloc(sizeof(t_img *) * 12);
	if (!platform)
	{
		ft_mini_free(game);
		return (0);
	}
	size[0] = 256;
	size[1] = 96;
	src = ft_open_image(game->mlx, "img/platformertiles.xpm", size, 0);
	if (!src)
	{
		free(platform);
		ft_mini_free(game);
		return (0);
	}
	size[0] = 256 / 8;
	size[1] = 96 / 3;
	i = 0;
	while (i < 9)
	{
		coor[0] = (size[0]) * (i / 3);
		coor[1] = (size[0]) * (i % 3);
		platform[i++] = ft_get_tile(src, coor, size, game->mlx);
	}
	i = 0;
	while (i < 3)
	{
		coor[0] = (size[0]) * 4;
		coor[0] = (size[0]) * i;
		platform[i + 9] = ft_get_tile(src, coor, size, game->mlx);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		if (!platform[i++])
		{
			ft_mini_free(game);
			return (0);
		}
		i++;
	}
	game->platform = platform;
	mlx_destroy_image(game->mlx, src->img);
	free(src);
	return (1);
}

t_img	*ft_get_tile(t_img *src, int coor[2], int size[2], void *mlx)
{
	t_img	*tile;
	int		x;
	int		y;

	tile = malloc(sizeof(t_img));
	if (!tile)
		return (NULL);
	tile->img = mlx_new_image(mlx, size[0], size[1]);
	if (!tile->img)
		free(tile);
	if (!tile->img)
		return (NULL);
	tile->data = mlx_get_data_addr(tile->img,
			&tile->bpp, &tile->size_line, &tile->edn);
	y = coor[1];
	while (y <= coor[1] + size[1])
	{
		x = coor[0] - 1;
		while (++x <= coor[0] + size[0])
			ft_put_pixel(tile, x, y, ft_get_pixel(src, x, y));
		y++;
	}
	tile->width = size[0];
	tile->height = size[1];
	return (tile);
}
