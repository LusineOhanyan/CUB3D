/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_for_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:05:35 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/17 16:16:52 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_argv(char *str)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	k = 0;
	while (str[i])
		i++;
	k = i;
	i = 0;
	while (str[i] != '.')
		i++;
	tmp = ft_substr(str, i, k);
	if (ft_strcmp(tmp, ".cub") != 0)
	{
		free(tmp);
		printf("wrong format\n");
		return (0);
	}
	free(tmp);
	return (1);
}

int	check_argv_for_xpm(char *str)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	while (str[i])
		i++;
	k = i;
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (i == ft_strlen(str))
		return (0);
	tmp = ft_strrchr(str, '.');
	if (tmp == NULL)
		return (0);
	if (ft_strcmp(tmp, ".xpm") != 0)
		return (0);
	return (1);
}

void	ft_check_digit_floor(t_vars *vars)
{
	int		i;
	char	**tmp;

	if (vars->floor != NULL)
	{
		tmp = ft_split(vars->floor[1], ',');
		if (tmp[3] != NULL)
		{
			printf("wrong arguments\n");
			exit(1);
		}
		i = -1;
		while (tmp[++i] && i < 3)
		{
			check_digit(tmp[i]);
			vars->f_color[i] = ft_atoi(tmp[i]);
		}
		free_double(tmp);
	}
}

void	ft_check_digit_ceiling(t_vars *vars)
{
	int		i;
	char	**tmp;

	if (vars->ceiling != NULL)
	{
		tmp = ft_split(vars->ceiling[1], ',');
		if (tmp[3] != NULL)
		{
			printf("wrong arguments\n");
			exit(1);
		}
		i = 0;
		while (tmp[i] && i < 3)
		{
			check_digit(tmp[i]);
			vars->c_color[i] = ft_atoi(tmp[i]);
			i++;
		}
		free_double(tmp);
	}
}

void	print_errors(int *num)
{
	int	i;

	i = 0;
	while (i != 3)
	{
		if (!(num[i] >= 0 && num[i] <= 255))
		{
			printf("error\n");
			exit(1);
		}
		i++;
	}
}
