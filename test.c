/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:13:04 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/14 11:18:32 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

int my_get_pixel(void *img, int x, int y)
{
    char *data;
    int bpp;
    int size_line;
    int edn;

    // Récupération des données de l'image
    data = mlx_get_data_addr(img, &bpp, &size_line, &edn);

    // Calcul de l'adresse du pixel à la position (x, y)
    // Le bpp (bits par pixel) divisé par 8 donne la taille d'un pixel en octets
    int pixel_offset = (y * size_line) + (x * (bpp / 8));

    // Récupérer la couleur du pixel (sous forme d'un entier)
    int color = *(int *)(data + pixel_offset);

    return color;
}

void    my_put_pixel(void *buffer, int x, int y, int color)
{
    char *data;
    char *dst;
    int bpp;
    int size_line;
    int edn;

    // Récupération des données de l'image
    data = mlx_get_data_addr(buffer, &bpp, &size_line, &edn);


    // Calculer l'adresse du pixel à la position (x, y)
    dst = data + (y * size_line + x * (bpp / 8));
    
    // Mettre la couleur à cette adresse
    *(unsigned int*)dst = color;
}

void my_put_image(void *mlx, void *win, void *img, void *buffer)
{
    int img_width = 800;
    int img_height = 600;
    int x, y;
    int color;

    // Récupérer la taille de l'image

    for (y = 0; y < img_height; y++)
    {
        for (x = 0; x < img_width; x++)
        {
            // Récupérer la couleur du pixel
            color = my_get_pixel(img, x, y);

            // Vérifier si le pixel n'est pas transparent (en supposant 0x00000000 comme transparent)
            if (color >= 0)
            {
                // Utiliser mlx_pixel_put pour afficher le pixel
                my_put_pixel(buffer, x, y, color);
            }
        }
    }
}

int	main(void)
{
	void	*mlx;
	void	*window;
	void	*img1;
	void	*img2;
    void    *buffer;
	int	width = 800;
	int	height = 600;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "test");
    buffer = mlx_new_image(mlx, 800, 600);
	img1 = mlx_xpm_file_to_image(mlx, "img/bg.xpm", &width, &height);
	img2 = mlx_xpm_file_to_image(mlx, "img/montain-far.xpm", &width, &height);
	if (!img1)
		return (0);
	if (!img2)
		return (0);
	my_put_image(mlx, window, img1, buffer);
	my_put_image(mlx, window, img2, buffer);
    mlx_put_image_to_window(mlx, window, buffer, 0, 0);
	mlx_loop(mlx);
}
