/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:17:57 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/03 21:17:58 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_images_bg(t_game *game, t_img *backgrounds[3])
{
	void	*mlx;
	int		width;
	int		height;

	mlx = game->mlx;
	width = game->w_width;
	height = game->w_height;
	backgrounds[0] = ft_open_image(mlx, "textures/BG_3.xpm", width, height);
	if (!backgrounds[0])
		ft_error("Cannot open background image", game);
	backgrounds[1] = ft_open_image(mlx, "textures/BG_2.xpm", width, height);
	if (!backgrounds[1])
		ft_error("Cannot open background image", game);
	backgrounds[2] = ft_open_image(mlx, "textures/BG_1.xpm", width, height);
	if (!backgrounds[2])
		ft_error("Cannot open background image", game);
}

void	ft_init_background(t_game *game)
{
	int		i;

	i = 0;
	while (i < 3)
		game->backgrounds[i++] = NULL;
	ft_init_images_bg(game, game->backgrounds);
}

void	ft_travelling_right(t_game *game)
{
	t_img	*cur_bg;

	cur_bg = game->backgrounds[1];
	cur_bg->x = (cur_bg->x + 1) % game->w_width;
	cur_bg = game->backgrounds[2];
	cur_bg->x = (cur_bg->x + 2) % game->w_width;
}

void	ft_travelling_left(t_game *game)
{
	t_img	*cur_bg;

	cur_bg = game->backgrounds[1];
	cur_bg->x = (cur_bg->x - 1) % cur_bg->width;
	cur_bg = game->backgrounds[2];
	cur_bg->x = (cur_bg->x - 2) % cur_bg->width;
}
