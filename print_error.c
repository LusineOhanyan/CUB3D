/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:54:16 by suhovhan          #+#    #+#             */
/*   Updated: 2023/05/18 15:27:04 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_addres *addres)
{
	free(addres->game->mlx);
	free(addres->game->win);
	free(addres->game->no);
	free(addres->game->so);
	free(addres->game->ea);
	free(addres->game->we);
	addres->game->mlx = NULL;
	addres->game->win = NULL;
	addres->game->no = NULL;
	addres->game->so = NULL;
	addres->game->ea = NULL;
	addres->game->we = NULL;
}

void	free_all(t_addres *addres)
{
	free_game(addres);
	free(addres->rcasting);
	free(addres->index);
	free(addres->game);
	free(addres->img);
	addres->rcasting = NULL;
	addres->index = NULL;
	addres->game = NULL;
	addres->img = NULL;
}

void	print_close(t_addres *address, char *str)
{
	write(1, str, ft_strlen(str));
	free_all(address);
}

int	close_game(t_addres *address)
{
	print_close(address, "Game closed\n");
	exit(0);
}
