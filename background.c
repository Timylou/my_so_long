/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:18:09 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/14 15:20:48 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_travelling_right(t_game *game)
{
	t_img	*cur_bg;

	cur_bg = game->backgrounds[0];
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[1];
	cur_bg->x += 3;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[2];
	cur_bg->x += 10;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[3];
	cur_bg->x += 30;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[4];
	cur_bg->x += 55;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
}

void	ft_travelling_left(t_game *game)
{
	t_img	*cur_bg;

	cur_bg = game->backgrounds[0];
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[1];
	cur_bg->x -= 3;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[2];
	cur_bg->x -= 10;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[3];
	cur_bg->x -= 30;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[4];
	cur_bg->x -= 55;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
}
