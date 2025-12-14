/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   independant_animation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:12:46 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/13 22:45:47 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_animate_star(t_game *game, long time, int x, int y)
{
	x = x * 64 - game->cam_x;
	y = y * 64 - game->cam_y;
	if (time > 150)
		ft_put_image_clean(game->star[0], x + 32, y, game->frame);
	else if (time > 100)
		ft_put_image_clean(game->star[1], x + 32, y, game->frame);
	else if (time > 50)
		ft_put_image_clean(game->star[2], x + 32, y, game->frame);
	else
		ft_put_image_clean(game->star[3], x + 32, y, game->frame);
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
		game->map[old_y][old_x] = '0';
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

void	ft_death_animation(t_game *game, int x, int y, int lft)
{
	static long	timer = 0;
	long		time;

	game->end = 1;
	time = get_time_ms();
	if (!timer)
		timer = time + 1800;
	if (time > timer + 500)
		mlx_loop_end(game->mlx);
	else if (timer - time > 1575)
		ft_put_image_clean(game->player->dead[0 + lft * 8], x, y, game->frame);
	else if (timer - time > 1350)
		ft_put_image_clean(game->player->dead[1 + lft * 8], x, y, game->frame);
	else if (timer - time > 1125)
		ft_put_image_clean(game->player->dead[2 + lft * 8], x, y, game->frame);
	else if (timer - time > 900)
		ft_put_image_clean(game->player->dead[3 + lft * 8], x, y, game->frame);
	else if (timer - time > 675)
		ft_put_image_clean(game->player->dead[4 + lft * 8], x, y, game->frame);
	else if (timer - time > 450)
		ft_put_image_clean(game->player->dead[5 + lft * 8], x, y, game->frame);
	else if (timer - time > 225)
		ft_put_image_clean(game->player->dead[6 + lft * 8], x, y, game->frame);
	else
		ft_put_image_clean(game->player->dead[7 + lft * 8], x, y, game->frame);
}

static void	ft_draw_attack(t_game *game, float x, float y, int look_left)
{
	int	i;
	int	px;
	int	py;

	px = x * 64 - game->cam_x;
	py = y * 64 - game->cam_y;
	if (!game->player->key_attack)
	{
		ft_put_image_clean(game->player->attack[look_left * 8], px, py, game->frame);
		return ;
	}
	i = (game->player->key_attack - 1) + look_left * 8;
	ft_put_image_clean(game->player->attack[i], px, py, game->frame);
}

void	ft_attack_animation(t_game *game, int look_left)
{
	static long	timer = 0;
	long		time;

	time = get_time_ms();
	if (!timer)
		timer = time + 800;
	if (time > timer)
		timer = 0;
	else if (timer - time > 700)
		game->player->key_attack = 1;
	else if (timer - time > 600)
		game->player->key_attack = 2;
	else if (timer - time > 500)
		game->player->key_attack = 3;
	else if (timer - time > 400)
		game->player->key_attack = 4;
	else if (timer - time > 300)
		game->player->key_attack = 5;
	else if (timer - time > 200)
		game->player->key_attack = 6;
	else if (timer - time > 100)
		game->player->key_attack = 7;
	else
		game->player->key_attack = 0;
	ft_draw_attack(game, game->player->x, game->player->y, look_left);
}
