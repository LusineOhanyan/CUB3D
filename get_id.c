/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:30:54 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/17 16:17:02 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_strdup1(char **tmp)
{
	int		i;
	char	**map;

	i = 0;
	while (tmp[i])
		i++;
	map = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tmp[i])
	{
		map[i] = ft_strdup(tmp[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	get_identifiers(t_vars *vars)
{
	int		i;
	char	**str;

	i = -1;
	while (vars->col_texture[++i])
	{
		str = ft_split(vars->col_texture[i], ' ');
		if (ft_strcmp(str[0], "NO") == 0 && vars->no == NULL)
		{
			check_path_argument(str);
			vars->no = ft_strdup1(str);
		}
		else if (ft_strcmp(str[0], "SO") == 0 && vars->so == NULL)
		{
			check_path_argument(str);
			vars->so = ft_strdup1(str);
		}
		free_double(str);
	}
}

void	get_identifiers1(t_vars *vars)
{
	int		i;
	char	**str;

	i = 0;
	while (vars->col_texture[i])
	{
		str = ft_split(vars->col_texture[i], ' ');
		if (ft_strcmp(str[0], "WE") == 0 && vars->we == NULL)
		{
			check_path_argument(str);
			vars->we = ft_strdup1(str);
		}
		else if (ft_strcmp(str[0], "EA") == 0 && vars->ea == NULL)
		{
			check_path_argument(str);
			vars->ea = ft_strdup1(str);
		}
		i++;
		free_double(str);
	}
}

void	get_identifiers2(t_vars *vars)
{
	int		i;
	char	**str;

	i = 0;
	while (vars->col_texture[i])
	{
		str = split_texture(vars->col_texture[i]);
		if (ft_strcmp(str[0], "F") == 0 && vars->floor == NULL)
		{
			check_path_argument(str);
			vars->floor = ft_strdup1(str);
		}
		else if (ft_strcmp(str[0], "C") == 0 && vars->ceiling == NULL)
		{
			check_path_argument(str);
			vars->ceiling = ft_strdup1(str);
		}
		i++;
		free_double(str);
	}
}

void	check_player(t_vars *vars)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	j = -1;
	flag = 0;
	while (vars->map[++i])
	{
		while (vars->map[i][++j])
			check_count_player(vars->map[i], &flag, j);
		j = -1;
	}
	check_flag(flag);
}
