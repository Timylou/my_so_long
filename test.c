/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:13:04 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/15 17:33:50 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minilibx-linux/mlx.h"
#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*window;
	t_img	*src;
	t_img	*tile;
    t_img	*buffer;
	int		size[2] = {256, 96};
	int		coor[2] = {(256 / 8) * 3, 0};
	int		size_tile[2] = {256 / 8, 96 / 3};
	
	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "test");
    buffer = malloc(sizeof(t_img));
	buffer->img = mlx_new_image(mlx, 800, 600);
	buffer->data = mlx_get_data_addr(buffer->img, &buffer->bpp, &buffer->size_line, &buffer->edn);
	src = ft_open_image(mlx, "img/platformertiles.xpm", size, 0);
	tile = ft_get_tile(src, coor, size_tile, mlx);
	for (int x=0; x < 25; x++)
	{
		ft_put_image(tile, size_tile[0] * x, 200, buffer);
   		mlx_put_image_to_window(mlx, window, buffer->img, 0, 0);
		sleep(1);
	}
	sleep(3);
}
