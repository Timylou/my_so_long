/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:46:10 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/15 21:13:09 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		mlx_loop_end(game->mlx);
	if (keysym == XK_d)
		ft_travelling_right(game);
	if (keysym == XK_a)
		ft_travelling_left(game);
	
	ft_put_image(game->platform[0], 0, 600 - 32, game->buffer);
	for (int i=32; i < 800 - 32; i += 32)
		ft_put_image(game->platform[1], i, 600 - 32, game->buffer);
	ft_put_image(game->platform[2], 800 - 32, 600 - 32, game->buffer);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer->img, 0, 0);
	return (1);
}
