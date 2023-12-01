/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_for_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:33:47 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/18 16:59:58 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_vars *vars)
{
	int	i;

	i = -1;
	while (vars->map[++i])
	{
		if (check_symbol(vars->map[i]) == 1)
		{
			printf("error0\n");
			break ;
		}
	}
}

void	ft_check_wall(char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0')
			{
				if (!map[j][i + 1] || (map[j][i + 1] && map[j][i + 1] != '0'
					&& map[j][i + 1] != '1' && map[j][i + 1] != 'W'
					&& map[j][i + 1] != 'S' && map[j][i + 1] != 'E'
					&& map[j][i + 1] != 'N'))
				{
					printf("error1\n");
					exit(1);
				}
			}
		}
	}
}

void	ft_check_wall1(char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (i == 0 && map[j][i] == '0')
			{
				printf("error2\n");
				exit(1);
			}				
			if (i == ft_strlen(map[j]) || (i > 0 && map[j][i] == '0'
				&& map[j][i - 1] != 'S' && map[j][i - 1] != 'E'
				&& map[j][i - 1] != '1' && map[j][i - 1] != 'W'
				&& map[j][i - 1] != 'N' && map[j][i - 1] != '0'))
			{
				printf("error3\n");
				exit(1);
			}
		}
	}
}

void	check_character(char **map)
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
				if (((i == 0) || (!map[i + 1])) || ((map[i][j + 1]
						&& map[i][j + 1] != '0' && map[i][j + 1] != '1')
					|| (j > 0 && map[i][j - 1] != '0' && map[i][j - 1] != '1')))
				{
					printf("error\n");
					exit(1);
				}
			}
		}
	}
}

void	ft_check_wall2(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' && ((map[i + 1]
				&& ((ft_strlen(map[i + 1]) < j)
				|| (map[i + 1][j] != '0' && map[i + 1][j] != '1'
				&& map[i + 1][j] != 'W'
				&& map[i + 1][j] != 'S' && map[i + 1][j] != 'E'
				&& map[i + 1][j] != 'N')))
				|| (i > 0 && ((ft_strlen(map[i - 1]) < j)
				|| (map[i - 1][j] != '0' && map[i - 1][j] != '1'
				&& map[i - 1][j] != 'W' && map[i - 1][j] != 'S'
				&& map[i - 1][j] != 'E' && map[i - 1][j] != 'N')))))
			{
				printf("error7\n");
				exit(1);
			}
		}
	}
}
