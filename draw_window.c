/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:18:13 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/16 15:48:41 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int r, int g, int b)
{
	int	t;

	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	initializer(t_addres *address)
{
	address->game->mlx = mlx_init();
	address->game->win = mlx_new_window(address->game->mlx, WIDTH, \
	HEIGHT, "IT IS MY CUB3D!");
	address->game->no = mlx_xpm_file_to_image(address->game->mlx, \
	address->vars.no[1], &address->img[1].width, &address->img[1].height);
	address->game->so = mlx_xpm_file_to_image(address->game->mlx, \
	address->vars.so[1], &address->img[2].width, &address->img[2].height);
	address->game->ea = mlx_xpm_file_to_image(address->game->mlx, \
	address->vars.ea[1], &address->img[3].width, &address->img[3].height);
	address->game->we = mlx_xpm_file_to_image(address->game->mlx, \
	address->vars.we[1], &address->img[4].width, &address->img[4].height);
	address->game->f_color = create_trgb(address->vars.f_color[0], \
	address->vars.f_color[1], address->vars.f_color[2]);
	address->game->c_color = create_trgb(address->vars.c_color[0], \
	address->vars.c_color[1], address->vars.c_color[2]);
	if (address->game->mlx == NULL || address->game->win == NULL)
		close_game(address);
	if (address->game->no == NULL || address->game->so == NULL)
		close_game(address);
	if (address->game->we == NULL || address->game->ea == NULL)
		close_game(address);
}
