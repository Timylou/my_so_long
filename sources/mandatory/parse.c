/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:03:43 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/04 15:03:44 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static int	ft_get_map_height(char *filemap, t_game *game)
{
	int		fd;
	char	*line;
	int		height;
	int		width_flag;

	fd = open(filemap, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open map file\n", game);
	width_flag = 0;
	height = 0;
	line = get_next_line(fd);
	game->m_width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line) != game->m_width + 1)
			width_flag = 1;
		height++;
	}
	close(fd);
	if (height < 5 || width_flag || game->m_width < 5)
		ft_error("Map must be a rectangle with a 5< lenght and width\n", game);
	return (height);
}

static void	ft_check_filename(char *filename, t_game *game)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (len < 4)
		ft_error("map name too short\n", game);
	if (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e' && filename [len - 1] == 'r')
		return ;
	ft_error("The map must be a .ber\n", game);
}

static void	ft_check_map(t_game *game, int coins, int exit, int player)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->m_height)
	{
		x = -1;
		while (++x < game->m_width)
		{
			if ((x == 0 || x == game->m_width - 1
					|| y == 0 || y == game->m_height - 1)
				&& game->map[y][x] != '1')
				ft_error("The map must be surrounded by walls\n", game);
			if (game->map[y][x] == 'C')
				coins++;
			else if (game->map[y][x] == 'P' && ++player)
				ft_set_pos_player(game, x, y);
			else if (game->map[y][x] == 'E')
				exit++;
		}
	}
	if (player != 1 || exit != 1 || !coins)
		ft_error("Map must have 1 player, 1 exit and at least 1 coin\n", game);
	game->coins = coins;
}

static void	ft_read_map(t_game *game, int fd)
{
	char	*line;
	int		i;

	game->map = malloc(sizeof(char *) * game->m_height);
	if (!game->map)
	{
		close(fd);
		ft_error("Malloc error map\n", game);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[game->m_width - 2] == '\n')
			line[game->m_width - 2] = 0;
		game->map[i++] = line;
		line = get_next_line(fd);
	}
	close(fd);
	ft_check_map(game, 0, 0, 0);
}

void	ft_parse(t_game *game, char *filemap)
{
	int		fd;

	ft_check_filename(filemap, game);
	game->m_height = ft_get_map_height(filemap, game);
	fd = open(filemap, O_RDONLY);
	if (fd < 0)
		ft_error("Cannot open map file\n", game);
	ft_read_map(game, fd);
	//TODO : verif si la map est winnable
}
