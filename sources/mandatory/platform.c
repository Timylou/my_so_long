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

void	ft_init_platforms(t_game *game)
{
	t_img	*tileset;

	tileset = ft_open_image(game->mlx, "textures/terrain.xpm", 320, 544);
	if (!tileset)
		ft_error("tileset image init\n", game);
	game->platforms[0] = ft_get_tile(tileset, 16, 6, game);
	ft_free_image(tileset, game);
}
