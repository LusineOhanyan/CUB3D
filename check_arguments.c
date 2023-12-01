/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:29:18 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/17 16:16:22 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_colors(t_vars *vars)
{
	if (vars->floor && vars->floor[1])
	{
		ft_check_digit_floor(vars);
		print_errors(vars->f_color);
	}
	if (vars->ceiling && vars->ceiling[1])
	{
		ft_check_digit_ceiling(vars);
		print_errors(vars->c_color);
	}
}

int	check_path_id(t_vars *vars)
{
	char	**tmp;
	int		i;

	i = 0;
	while (vars->col_texture[i])
	{
		tmp = split_texture(vars->col_texture[i]);
		if (ft_strcmp(tmp[0], "NO") != 0 && ft_strcmp(tmp[0], "SO") != 0
			&& ft_strcmp(tmp[0], "WE") != 0 && ft_strcmp(tmp[0], "EA") != 0
			&& ft_strcmp(tmp[0], "F") != 0 && ft_strcmp(tmp[0], "C") != 0)
		{
			free_double(tmp);
			printf("error\n");
			return (0);
		}
		i++;
		free_double(tmp);
	}
	return (1);
}

void	check_path_argument(char **str)
{
	if (str[2] != NULL || check_xpm(str) == 0)
	{
		printf("wrong format\n");
		exit(1);
	}
}

int	check_xpm(char	**str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str[0], "NO") == 0 || ft_strcmp(str[0], "SO") == 0
		|| ft_strcmp(str[0], "WE") == 0 || ft_strcmp(str[0], "EA") == 0)
	{
		if (check_argv_for_xpm(str[1]) == 0)
			return (0);
	}
	return (1);
}

void	check_param(t_vars *vars)
{
	if (vars->no == NULL || vars->so == NULL
		|| vars->ea == NULL || vars->we == NULL || vars->floor == NULL
		|| vars->ceiling == NULL)
	{
		printf("wrong parametr\n");
		exit(1);
	}
}
