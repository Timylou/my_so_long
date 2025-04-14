/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:58:33 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/25 15:04:42 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

static void	ft_check_name(char *name, t_game *game)
{
	int	len;

	len = 0;
	while (name[len])
		len++;
	if (len < 4)
		ft_error("Error\nmap name too short", game);
	if (name[len - 4] == '.' && name[len - 3] == 'b' && name[len - 2] == 'e'
		&& name [len - 1] == 'r')
		return ;
	ft_error("Error\nThe map must be a .ber", game);
}

static void	ft_read_map(t_map *map, int height, int width, int fd)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	if (!line)
	{
		map->height = height;
		if (width > 0)
			map->temp_map = malloc(sizeof(char *) * height);
		else
			map->temp_map = NULL;
		return ;
	}
	len = 0;
	while (line[len])
		len++;
	if ((len != width && width != -1) || width == -2)
		len = -2;
	ft_read_map(map, height + 1, len, fd);
	if (map->temp_map)
		map->temp_map[height] = line;
	else
		free(line);
}

static void	ft_fill_map(t_game *game, int fd)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		ft_error("malloc map", game);
	}
	map->map = NULL;
	map->temp_map = NULL;
	game->map = map;
	ft_read_map(map, 0, -1, fd);
	close(fd);
	if (!map->temp_map || !map->temp_map[0])
		ft_error("Error\nMap size error", game);
	i = 0;
	while (map->temp_map[0][i])
		i++;
	map->width = i - 1;
	ft_translate_map(map, game);
	if (map->width * 64 > game->width)
		ft_error("Error\nMap width off limits", game);
	if (map->height * 64 > game->height)
		ft_error("Error\nMap height off limits", game);
}

static void	ft_check_walls(t_map *map, t_game *game)
{
	int		i;
	t_case	**case_map;

	case_map = map->map;
	i = 0;
	while (i < map->width)
	{
		if (case_map[0][i] != WALL || case_map[map->height - 1][i] != WALL)
			ft_error("Error\nmap must be surrounded by walls", game);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (case_map[i][0] != WALL || case_map[i][map->width - 1] != WALL)
			ft_error("Error\nmap must be surrounded by walls", game);
		i++;
	}
}

void	ft_parse(char **argv, t_game *game)
{
	int	fd;

	ft_check_name(argv[1], game);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		ft_error(argv[1], game);
	}
	ft_fill_map(game, fd);
	ft_check_walls(game->map, game);
}
