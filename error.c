/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:11:26 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/21 18:27:26 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *name, t_game *game)
{
	ft_mini_free(game);
	perror(name);
	exit(EXIT_FAILURE);
}

static void	ft_free_image(t_img *img, t_game *game)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(game->mlx, img->img);
	free(img);
}

static void	ft_free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (i < map->height)
			free(map->map[i++]);
		free(map->map);
	}
	if (map->temp_map)
	{
		i = 0;
		while (i < map->height)
			free(map->temp_map[i++]);
		free(map->temp_map);
	}
	free(map);
}

static void	ft_free_player(t_player *player, t_game *game)
{
	if (!player)
		return ;
	ft_free_image(player->img_up, game);
	ft_free_image(player->img_down, game);
	ft_free_image(player->img_right, game);
	ft_free_image(player->img_left, game);
	free(player);
}

void	*ft_mini_free(t_game *game)
{
	if (!game)
		return (NULL);
	ft_free_image(game->buffer, game);
	ft_free_image(game->ground, game);
	ft_free_image(game->img_coin, game);
	ft_free_image(game->wall, game);
	ft_free_image(game->exit, game);
	ft_free_map(game->map);
	ft_free_player(game->player, game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	return (NULL);
}
