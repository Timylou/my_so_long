/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:07:19 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/15 21:02:16 by yel-mens         ###   ########.fr       */
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

static void	ft_destroy_array_images(t_game *game, t_img **array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i])
		{
			if (array[i]->img)
				mlx_destroy_image(game->mlx, array[i]->img);
			free(array[i]);
		}
		i++;
	}
	free(array);
}

void	*ft_mini_free(t_game *game)
{
	if (!game)
		return (NULL);
	if (game->backgrounds)
		ft_destroy_array_images(game, game->backgrounds, 5);
	if (game->platform)
		ft_destroy_array_images(game, game->platform, 12);
	if (game->buffer)
	{
		if (game->buffer->img)
			mlx_destroy_image(game->mlx, game->buffer->img);
		free(game->buffer);
	}
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
	return (game);
}
