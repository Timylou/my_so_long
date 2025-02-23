/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:52:07 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/23 20:09:39 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_mlx_win(t_game *game)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
	{
		free(game);
		perror("mlx init");
		exit(EXIT_FAILURE);
	}
	game->width = 1600;
	game->height = 900;
	win = mlx_new_window(mlx, game->width, game->height, "so looong");
	if (!win)
	{
		free(game);
		mlx_destroy_display(mlx);
		free(mlx);
		perror("mlx window");
		exit(EXIT_FAILURE);
	}
	game->mlx = mlx;
	game->win = win;
}

static int	ft_init_buffer(t_game *game)
{
	game->buffer = malloc(sizeof(t_img));
	if (!game->buffer)
		ft_error("malloc buffer", game);
	game->buffer->img = mlx_new_image(game->mlx, game->width, game->height);
	if (!game->buffer->img)
		ft_error("buffer image init", game);
	game->buffer->data = mlx_get_data_addr(game->buffer->img,
			&game->buffer->bpp, &game->buffer->size_line, &game->buffer->edn);
	game->buffer->width = game->width;
	game->buffer->height = game->height;
	return (1);
}

static void	ft_init_variables(t_game *game)
{
	int		i;
	int		j;
	t_map	*map;

	game->steps = 0;
	game->coins = 0;
	map = game->map;
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->map[j][i] == PLAYER)
			{
				game->player->x = i;
				game->player->y = j;
				map->map[j][i] = EMPTY;
			}
			if (map->map[j][i] == COIN)
				game->coins++;
			i++;
		}
		j++;
	}
}

t_game	*ft_init_game(char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		perror("game malloc");
		exit(EXIT_FAILURE);
	}
	ft_init_mlx_win(game);
	ft_init_buffer(game);
	ft_parse(argv, game);
	ft_init_game_images(game);
	ft_init_player(game);
	ft_init_variables(game);
	return (game);
}
