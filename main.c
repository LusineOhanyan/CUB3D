/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:32:50 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/16 19:20:33 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	utils_main(int fd2, int fd)
{
	t_addres	addres;
	int			count;

	count = count_map(fd2);
	init_structs(&addres);
	parsing(fd, count, &(addres.vars));
	initializer(&addres);
	init_win(&addres);
	mlx_hook(addres.game->win, 17, 1L << 0, close_game, &addres);
	mlx_hook(addres.game->win, 2, 1L << 0, key_manager, &addres);
	mlx_loop(addres.game->mlx);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			fd2;

	if (argc == 2)
	{
		if (check_argv(argv[1]) == 1)
		{
			fd = open(argv[1], O_RDONLY);
			if (fd == -1)
			{
				perror("open: ");
				return (1);
			}
			fd2 = open(argv[1], O_RDONLY);
			if (fd2 == -1)
			{
				perror("open: ");
				return (1);
			}
			utils_main(fd2, fd);
		}
	}
	return (0);
}
