/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:07:19 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/14 15:23:48 by yel-mens         ###   ########.fr       */
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

void	ft_mini_free(t_game *game)
{
	int	i;

	if (game)
	{
		if (game->backgrounds)
		{
			i = -1;
			while (++i < 5)
			{
				if (!game->backgrounds[i])
					continue ;
				mlx_destroy_image(game->mlx, game->backgrounds[i]->img);
				free(game->backgrounds[i]);
			}
			free(game->backgrounds);
		}
		if (game->buffer && game->buffer->img)
			mlx_destroy_image(game->mlx, game->buffer->img);
		if (game->buffer)
			free(game->buffer);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game);
	}
}

static int	ft_init_background(t_game *game)
{
	t_img	**backgrounds;

	backgrounds = malloc(sizeof(t_img *) * 5);
	if (!backgrounds)
	{
		ft_mini_free(game);
		return (0);
	}
	game->backgrounds = backgrounds;
	return (1);
}

static int	ft_init_images(t_game *game)
{
	void	*mlx;
	int		i;

	i = 0;
	mlx = game->mlx;
	game->backgrounds[0] = ft_open_image(mlx, "img/bg.xpm", 800, 600, 0);
	if (!game->backgrounds[0])
		i++;
	game->backgrounds[1] = ft_open_image(mlx, "img/montain-far.xpm", 800, 600, 80);
	if (!game->backgrounds[1])
		i++;
	game->backgrounds[2] = ft_open_image(mlx, "img/mountains.xpm", 800, 600, 328);
	if (!game->backgrounds[2])
		i++;
	game->backgrounds[3] = ft_open_image(mlx, "img/trees.xpm", 800, 600, 340);
	if (!game->backgrounds[3])
		i++;
	game->backgrounds[4] = ft_open_image(mlx, "img/fgd-trees.xpm", 800, 600, 340);
	if (!game->backgrounds[4])
		i++;
	game->buffer = malloc(sizeof(t_img));
	if (!game->buffer)
		return (-1);
	game->buffer->img = mlx_new_image(game->mlx,game->width, game->height);
	return (i);
}

t_game	*ft_init_game(void)
{
	t_game	*game;
	int		i;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	if (!ft_init_mlx_win(game))
		return (NULL);
	if (!ft_init_background(game))
		return (NULL);
	i = ft_init_images(game);
	if (i != 0)
	{
		ft_mini_free(game);
		return (NULL);
	}
	if (!game->buffer->img)
		ft_mini_free(game);
	if (!game->buffer->img)
		return (NULL);
	game->buffer->data = mlx_get_data_addr(game->buffer->img,
			&game->buffer->bpp, &game->buffer->size_line, &game->buffer->edn);
	game->buffer->width = 800;
	game->buffer->height = 600;
	return (game);
}
