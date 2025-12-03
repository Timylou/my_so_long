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

static void	ft_init_images_bg(t_game *game, t_img *backgrounds[5])
{
	void	*mlx;
	int		width;
	int		height;

	mlx = game->mlx;
	width = game->w_width;
	height = game->w_height;
	backgrounds[0] = ft_open_image(mlx, "textures/bg.xpm", width, height);
	if (!backgrounds[0])
		ft_error("Cannot open background image", game);
	backgrounds[1] = ft_open_image(mlx, "textures/montfar.xpm", width, height);
	if (!backgrounds[1])
		ft_error("Cannot open background image", game);
	backgrounds[2] = ft_open_image(mlx, "textures/mount.xpm", width, height);
	if (!backgrounds[2])
		ft_error("Cannot open background image", game);
	backgrounds[3] = ft_open_image(mlx, "textures/trees.xpm", width, height);
	if (!backgrounds[3])
		ft_error("Cannot open background image", game);
	backgrounds[4] = ft_open_image(mlx, "textures/fgd-trees.xpm", width, height);
	if (!backgrounds[4])
		ft_error("Cannot open background image", game);
}

void	ft_init_background(t_game *game)
{
	int		i;

	i = 0;
	while (i < 5)
		game->backgrounds[i++] = NULL;
	ft_init_images_bg(game, game->backgrounds);
	game->backgrounds[1]->y = 80;
	game->backgrounds[2]->y = 328;
	game->backgrounds[3]->y = 340;
	game->backgrounds[4]->y = 340;
}

void	ft_travelling_right(t_game *game)
{
	t_img	*cur_bg;

	cur_bg = game->backgrounds[1];
	cur_bg->x = (cur_bg->x + 1) % game->w_width;
	cur_bg = game->backgrounds[2];
	cur_bg->x = (cur_bg->x + 2) % game->w_width;
	cur_bg = game->backgrounds[3];
	cur_bg->x = (cur_bg->x + 3) % game->w_width;
	cur_bg = game->backgrounds[4];
	cur_bg->x = (cur_bg->x + 5) % game->w_width;
}

void	ft_travelling_left(t_game *game)
{
	t_img	*cur_bg;

	cur_bg = game->backgrounds[1];
	cur_bg->x = (cur_bg->x - 1) % game->w_width;
	cur_bg = game->backgrounds[2];
	cur_bg->x = (cur_bg->x - 2) % game->w_width;
	cur_bg = game->backgrounds[3];
	cur_bg->x = (cur_bg->x - 3) % game->w_width;
	cur_bg = game->backgrounds[4];
	cur_bg->x = (cur_bg->x - 5) % game->w_width;
}
