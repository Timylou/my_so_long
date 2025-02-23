/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:13:35 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/23 20:26:46 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_win(t_game *game)
{
    write(1, "You Won !\n", 10);
    mlx_loop_end(game->mlx);
}

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(game->mlx);
		return (1);
	}
	if (keysym == XK_w)
		ft_player_mouvement(game->player, game, UP);
	else if (keysym == XK_a)
		ft_player_mouvement(game->player, game, LEFT);
	else if (keysym == XK_s)
		ft_player_mouvement(game->player, game, DOWN);
	else if (keysym == XK_d)
		ft_player_mouvement(game->player, game, RIGHT);
	ft_map_to_buffer(game);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer->img, 0, 0);
	return (1);
}
