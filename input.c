/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:46:10 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/14 15:06:42 by yel-mens         ###   ########.fr       */
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
	mlx_put_image_to_window(game->mlx, game->win, game->buffer->img, 0, 0);
	return (1);
}
