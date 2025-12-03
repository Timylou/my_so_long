/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:08:11 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/03 22:08:12 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(game->mlx);
		return (1);
	}
	if (keysym == XK_w || keysym == XK_Up || keysym == XK_space)
		game->player->key_jump = 1;
	else if (keysym == XK_a || keysym == XK_Left)
	{
		if (!game->player->key_right)
			game->player->key_left = 1;
		ft_travelling_right(game); // a deplacer
	}
	else if (keysym == XK_d || keysym == XK_Right)
	{
		if (!game->player->key_left)
			game->player->key_right = 1;
		ft_travelling_left(game); // a deplacer
	}
	return (1);
}

int	ft_handle_release(int keysym, t_game *game)
{
	if (keysym == XK_w || keysym == XK_Up || keysym == XK_space)
		game->player->key_jump = 0;
	else if (keysym == XK_a || keysym == XK_Left)
		game->player->key_left = 0;
	else if (keysym == XK_d || keysym == XK_Right)
		game->player->key_right = 0;
	return (1);
}
