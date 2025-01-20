/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:33:55 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/16 11:46:23 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*ft_open_src(t_game *game, t_img **platform)
{
	t_img	*src;
	int		size[2];

	size[0] = 256;
	size[1] = 96;
	src = ft_open_image(game->mlx, "img/platformertiles.xpm", size, 0);
	if (!src)
	{
		free(platform);
		ft_mini_free(game);
		return (NULL);
	}
	return (src);
}

static void	ft_init_all_platforms(t_img **platform, t_img *src, void *mlx)
{
	int	size[2];
	int	coor[2];
	int	i;

	size[0] = 256 / 8;
	size[1] = 96 / 3;
	i = 0;
	while (i < 9)
	{
		coor[0] = (size[0]) * (i / 3);
		coor[1] = (size[0]) * (i % 3);
		platform[i++] = ft_get_tile(src, coor, size, mlx);
	}
	i = 0;
	while (i < 3)
	{
		coor[0] = (size[0]) * 4;
		coor[0] = (size[0]) * i;
		platform[i + 9] = ft_get_tile(src, coor, size, mlx);
		i++;
	}
}

static int	ft_check_platforms(t_game *game, t_img **platform)
{
	int		i;

	i = 0;
	while (i < 12)
	{
		if (!platform[i++])
		{
			ft_mini_free(game);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_init_platform(t_game *game)
{
	t_img	**platform;
	t_img	*src;

	platform = malloc(sizeof(t_img *) * 12);
	if (!platform)
	{
		ft_mini_free(game);
		return (0);
	}
	src = ft_open_src(game, platform);
	if (!src)
		return (0);
	ft_init_all_platforms(platform, src, game->mlx);
	if (!ft_check_platforms(game, platform))
		return (0);
	game->platform = platform;
	mlx_destroy_image(game->mlx, src->img);
	free(src);
	return (1);
}
