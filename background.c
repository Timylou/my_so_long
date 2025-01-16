/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:18:09 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/15 17:53:36 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_init_images_bg(t_game *game, int size[2])
{
	void	*mlx;
	int		i;

	i = 0;
	mlx = game->mlx;
	game->backgrounds[0] = ft_open_image(mlx, "img/bg.xpm", size, 0);
	if (!game->backgrounds[0])
		i++;
	game->backgrounds[1] = ft_open_image(mlx, "img/montain-far.xpm", size, 80);
	if (!game->backgrounds[1])
		i++;
	game->backgrounds[2] = ft_open_image(mlx, "img/mountains.xpm", size, 328);
	if (!game->backgrounds[2])
		i++;
	game->backgrounds[3] = ft_open_image(mlx, "img/trees.xpm", size, 340);
	if (!game->backgrounds[3])
		i++;
	game->backgrounds[4] = ft_open_image(mlx, "img/fgd-trees.xpm", size, 340);
	if (!game->backgrounds[4])
		i++;
	return (i);
}

int	ft_init_background(t_game *game)
{
	t_img	**backgrounds;
	int		size[2];
	int		i;

	backgrounds = malloc(sizeof(t_img *) * 5);
	if (!backgrounds)
	{
		ft_mini_free(game);
		return (0);
	}
	game->backgrounds = backgrounds;
	size[0] = 800;
	size[1] = 600;
	i = ft_init_images_bg(game, size);
	if (i != 0)
		ft_mini_free(game);
	if (i != 0)
		return (0);
	return (1);
}

void	ft_travelling_right(t_game *game)
{
	t_img	*cur_bg;

	cur_bg = game->backgrounds[0];
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[1];
	cur_bg->x = (cur_bg->x + 1) % 800;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[2];
	cur_bg->x = (cur_bg->x + 2) % 800;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[3];
	cur_bg->x = (cur_bg->x + 3) % 800;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[4];
	cur_bg->x = (cur_bg->x + 5) % 800;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
}

void	ft_travelling_left(t_game *game)
{
	t_img	*cur_bg;

	cur_bg = game->backgrounds[0];
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[1];
	cur_bg->x = (cur_bg->x - 1) % 800;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[2];
	cur_bg->x = (cur_bg->x - 2) % 800;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[3];
	cur_bg->x = (cur_bg->x - 3) % 800;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
	cur_bg = game->backgrounds[4];
	cur_bg->x = (cur_bg->x - 5) % 800;
	ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->buffer);
}
