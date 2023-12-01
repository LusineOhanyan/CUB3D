/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:36:36 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/18 16:47:30 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checking(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' && (i == 0 || map[i + 1] == NULL))
			{
				printf("error\n");
				exit(1);
			}
		}
	}
}

void	utils_new_map(int count)
{
	if (count > 6)
	{
		printf("error66\n");
		exit (1);
	}
}

int	check_extra(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32 && str[i] <= 127)
			return (0);
		else
			break ;
		i++;
	}
	return (1);
}
