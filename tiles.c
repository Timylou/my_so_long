/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:56:24 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/16 11:34:20 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*ft_get_tile(t_img *src, int cr[2], int size[2], void *mlx)
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
	y = 0;
	while (y < size[1])
	{
		x = -1;
		while (++x < size[0])
			ft_put_pixel(tile, x, y, ft_get_pixel(src, cr[0] + x, cr[1] + y));
		y++;
	}
	tile->width = size[0];
	tile->height = size[1];
	return (tile);
}
