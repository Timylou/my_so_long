/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:49:19 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/11 16:49:19 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_mouvement(char block)
{
	return (!('0' < block && block < '8'));
}

float	ft_jump(t_game *game, float dt)
{
	float	new_y;
	float	g;

	if (dt > 0.15)
		dt = 0.15;
	g = -GRAVITY;
	if (game->player->velocity < 0)
		g = -GRAVITY - 3;
	if (!game->player->key_jump)
		return (game->player->y);
	new_y = game->player->y - game->player->velocity * dt;
	game->player->velocity += (g * dt);
	if (new_y < 0)
		new_y = 0;
	if (game->player->velocity < 0 && new_y > game->m_height - 2)
	{
		new_y = game->m_height - 2;
		game->player->key_jump = 0;
		game->player->velocity = VELOCITY;
		return (new_y);
	}
	if (new_y < game->m_height - 2.5 && (game->player->velocity < 0) && (game->map[(int)(new_y + 1)][(int)(game->player->x)] == '1'))
	{
		game->player->key_jump = 0;
		game->player->velocity = VELOCITY;
		return ((int)new_y);
	}
	if (game->map[(int)new_y][(int)(game->player->x)] != '1')
		return (new_y);
	return (game->player->y);
}
