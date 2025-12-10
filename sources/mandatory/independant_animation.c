/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   independant_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:12:46 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/10 15:12:47 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_animate_star(t_game *game, long time, int x, int y)
{
	x = x * 64 - game->cam_x;
	y = y * 64 - game->cam_y;
	if (time > 150)
		ft_put_image_clean(game->star[0], x, y, game->frame);
	else if (time > 100)
		ft_put_image_clean(game->star[1], x, y, game->frame);
	else if (time > 50)
		ft_put_image_clean(game->star[2], x, y, game->frame);
	else
		ft_put_image_clean(game->star[3], x, y, game->frame);
}

void	ft_star_animation(t_game *game, int x, int y)
{
	static long	timer = 0;
	static int	old_x = 0;
	static int	old_y = 0;
	long		time;

	time = get_time_ms();
	if (!(x == old_x && y == old_y))
	{
		timer = time + 200;
		old_x = x;
		old_y = y;
	}
	if (time > timer)
	{
		game->map[y][x] = '0';
		return ;
	}
	ft_animate_star(game, timer - time, x, y);
}
