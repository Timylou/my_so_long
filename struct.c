/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:07:19 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/17 11:29:19 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_init_mlx_win(t_game *game)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
	{
		free(game);
		return (0);
	}
	game->width = 800;
	game->height = 600;
	win = mlx_new_window(mlx, game->width, game->height, "so looong");
	if (!win)
	{
		free(game);
		mlx_destroy_display(mlx);
		free(mlx);
		return (0);
	}
	game->mlx = mlx;
	game->win = win;
	return (1);
}

static void	ft_destroy_array_images(void *mlx, t_img **array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i])
		{
			if (array[i]->img)
				mlx_destroy_image(mlx, array[i]->img);
			free(array[i]);
		}
		i++;
	}
	free(array);
}

static void	ft_destroy_player(t_player *player, void *mlx)
{
	if (player->idle)
		ft_destroy_array_images(mlx, player->idle, 12);
	if (player->idle)
		ft_destroy_array_images(mlx, player->run, 10);
	if (player->hurt)
		ft_destroy_array_images(mlx, player->hurt, 6);
	if (player->dead)
		ft_destroy_array_images(mlx, player->dead, 10);
	if (player->walk[0])
		ft_destroy_array_images(mlx, player->walk[0], 12);
	if (player->walk[1])
		ft_destroy_array_images(mlx, player->walk[1], 12);
	if (player->jump[0])
		ft_destroy_array_images(mlx, player->jump[0], 5);
	if (player->jump[1])
		ft_destroy_array_images(mlx, player->jump[1], 5);
}

void	*ft_mini_free(t_game *game)
{
	if (!game)
		return (NULL);
	if (game->backgrounds)
		ft_destroy_array_images(game->mlx, game->backgrounds, 5);
	if (game->platform)
		ft_destroy_array_images(game->mlx, game->platform, 12);
	if (game->buffer)
	{
		if (game->buffer->img)
			mlx_destroy_image(game->mlx, game->buffer->img);
		free(game->buffer);
	}
	if (game->player)
		ft_destroy_player(game->player, game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	return (NULL);
}

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	if (!ft_init_mlx_win(game))
		return (NULL);
	if (!ft_init_background(game))
		return (NULL);
	if (!ft_init_buffer(game))
		return (NULL);
	if (!ft_init_platform(game))
		return (NULL);
	if (!ft_init_player(game))
		return (NULL);
	return (game);
}
