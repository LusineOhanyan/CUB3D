/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:19:36 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/18 17:00:36 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_t_vars(t_vars *vars)
{
	vars->map = NULL;
	vars->col_texture = NULL;
	vars->no = NULL;
	vars->so = NULL;
	vars->we = NULL;
	vars->ea = NULL;
	vars->floor = NULL;
	vars->ceiling = NULL;
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	check_count_player(char *str, int *flag, int i)
{
	if (str[i] == 'S' || str[i] == 'N'
		|| str[i] == 'W' || str[i] == 'E')
	{
		if (*flag == 0)
			*flag = 1;
		else
		{
			printf("too many player\n");
			exit(1);
		}
	}
}

void	check_digit(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != ',')
		{
			printf("error\n");
			exit(1);
		}
		i++;
	}
}

void	checking_character(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'S'
				|| map[i][j] == 'N' || map[i][j] == 'E')
			{
				if ((map[i + 1] && ((ft_strlen(map[i + 1]) < j)
							|| (map[i + 1][j] != '0' && map[i + 1][j] != '1')))
						|| (i > 0 && ((ft_strlen(map[i + 1]) < j)
						|| (map[i - 1][j] != '0' && map[i - 1][j] != '1'))))
				{
					printf("error\n");
					exit(1);
				}
			}
		}
	}
}
