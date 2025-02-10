/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:23:16 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/10 18:02:51 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_background(t_game *game)
{
	int		size[2];

	size[0] = 64;
	size[1] = 64;
	game->background = ft_open_image(game->mlx, "img/ground.xpm", size);
	if (!game->background)
		ft_error("Background Init", game);
}
