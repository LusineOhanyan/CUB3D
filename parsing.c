/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:12:19 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/18 16:47:52 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	without_newline_map(char **map, int count)
{
	int	i;
	int	j;

	i = get_index_map(map, count);
	j = 0;
	i = i + 1;
	while (map[i])
	{
		if (map[i][0] && (map[i][0] == '\n' || map[i][0] == ' '))
			i++;
		else
			break ;
	}
	return (i);
}

char	**get_new_map(char	**map, t_vars *vars, int count)
{
	int	index;
	int	value;
	int	i;

	i = 0;
	index = without_newline_map(map, count);
	value = count - index;
	i = 0;
	vars->map = (char **)malloc((value + 1) * sizeof(char *));
	while (map[index])
	{
		vars->map[i] = ft_strdup(map[index]);
		check_new_line(vars->map[i]);
		i++;
		index++;
	}
	vars->map[i] = NULL;
	return (vars->map);
}

char	**ft_new_map_for_texture(char	**map, t_vars *vars, int count)
{
	int	i;
	int	k;
	int	num;

	i = -1;
	k = 0;
	num = get_index_map(map, count);
	count = 0;
	vars->col_texture = (char **)malloc((6 + 1) * sizeof(char *));
	while (map[++i] && i != (num + 1))
	{
		map[i] = ft_strtrim(map[i], "\n ");
		if (!check_symbol(map[i]))
			count++;
		utils_new_map(count);
		if (check_symbol(map[i]) == 0 && k < 6)
		{
			vars->col_texture[k] = ft_strdup(map[i]);
			k++;
		}
	}
	vars->col_texture[k] = NULL;
	return (vars->col_texture);
}

void	parsing_utils(t_vars *vars)
{
	ft_check_wall(vars->map);
	ft_check_wall1(vars->map);
	ft_check_wall2(vars->map);
	checking(vars->map);
	check_character(vars->map);
	checking_character(vars->map);
	check_player(vars);
	check_empty_line(vars);
}

void	parsing(int fd, int count, t_vars *vars)
{
	char	**map;
	int		i;

	i = -1;
	map = (char **)malloc((count + 1) * sizeof(char *));
	while (1)
	{
		map[++i] = get_next_line(fd);
		if (!ft_strlen(map[i]))
			break ;
	}
	map[i] = NULL;
	init_t_vars(vars);
	get_new_map(map, vars, count);
	parsing_utils(vars);
	ft_new_map_for_texture(map, vars, count);
	free_double(map);
	check_path_id(vars);
	get_identifiers(vars);
	get_identifiers1(vars);
	get_identifiers2(vars);
	check_param(vars);
	get_colors(vars);
}
