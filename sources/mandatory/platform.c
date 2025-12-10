/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:38:41 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/08 15:38:41 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_open_platforms(t_game *game)
{
	t_img	*tileset;

	tileset = ft_open_image(game->mlx, "textures/terrain.xpm", 1280, 2176);
	if (!tileset)
		ft_error("tileset image platform init\n", game);
	game->platforms[0] = ft_get_tile(tileset, 64, 5, game);
	game->platforms[1] = ft_get_tile(tileset, 128, 70, game);
	game->platforms[2] = ft_get_tile(tileset, 128, 60, game);
	game->platforms[3] = ft_get_tile(tileset, 128, 50, game);
	game->platforms[4] = flip_xpm_horizontally(game->platforms[1], game);
	game->platforms[5] = flip_xpm_horizontally(game->platforms[2], game);
	game->platforms[6] = flip_xpm_horizontally(game->platforms[3], game);
	ft_free_image(tileset, game);
}

void	ft_init_platforms(t_game *game)
{
	t_img	*tileset;
	int		i;

	ft_open_platforms(game);
	tileset = ft_open_image(game->mlx, "textures/portal.xpm", 96, 64);
	if (!tileset)
		ft_error("tileset portal init\n", game);
	i = -1;
	while (++i < 6)
		game->exit[i] = ft_get_tile(tileset, 128, i, game);
	ft_free_image(tileset, game);
	tileset = ft_open_image(game->mlx, "textures/apple.xpm", 128, 32);
	if (!tileset)
		ft_error("tileset apple.xpm\n", game);
	i = -1;
	while (++i < 4)
		game->apple[i] = ft_get_tile(tileset, 64, i, game);
	ft_free_image(tileset, game);
	tileset = ft_open_image(game->mlx, "textures/star.xpm", 320, 64);
	i = -1;
	while (++i < 4)
		game->star[i] = ft_get_tile(tileset, 64, i, game);
	ft_free_image(tileset, game);
}
