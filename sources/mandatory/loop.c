/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:16:06 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/03 22:16:06 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_loop(t_game *game)
{
	long	time;
	float	dt;

	dt = get_delta_time();
	time = get_time_ms() % 1000;
	ft_move_player(game, dt);
	ft_clear_frame(game);
	ft_draw_platforms(game);
	ft_draw_player(game, time);
	mlx_put_image_to_window(game->mlx, game->win, game->frame->img, 0, 0);
	return (1);
}
