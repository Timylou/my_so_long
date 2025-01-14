/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:44:06 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/14 15:05:22 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_pixel(t_img *img, int x, int y)
{
	int		pixel_pos;

	if (!img)
		return (-1);
	pixel_pos = (y * img->size_line) + (x * (img->bpp / 8));
	return (*(int *)(img->data + pixel_pos));
}

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + ((y * img->size_line) + (x * (img->bpp / 8)));
	*(unsigned int *)dst = color;
}

void	ft_put_image(t_img *img, int x_offset, int y_offset, t_img *buffer)
{
	int	x;
	int	y;
	int	color;

	if (!buffer || !img)
		return ;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color = ft_get_pixel(img, x, y);
			if (color >= 0)
				ft_put_pixel(buffer, x + x_offset, y + y_offset, color);
			x++;
		}
		y++;
	}
}

t_img	*ft_open_image(void *mlx, char *name, int width, int height, int y)
{
	t_img	*img;
	void	*mlx_img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	mlx_img = mlx_xpm_file_to_image(mlx, name, &width, &height);
	if (!mlx_img)
	{
		free(img);
		return (NULL);
	}
	img->width = width;
	img->height = height;
	img->img = mlx_img;
	img->data = mlx_get_data_addr(mlx_img,
			&img->bpp, &img->size_line, &img->edn);
	img->x = 0;
	img->y = y;
	return (img);
}
