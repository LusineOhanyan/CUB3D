/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:18 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/18 16:48:36 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_path(char *str, t_vars *vars)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "NO") == 0)
		return (vars->no[1]);
	else if (ft_strcmp(str, "SO") == 0)
		return (vars->so[1]);
	else if (ft_strcmp(str, "WE") == 0)
		return (vars->we[1]);
	else if (ft_strcmp(str, "EA") == 0)
		return (vars->ea[1]);
	return (0);
}

char	**split_texture(char *texture)
{
	char	**str;
	int		i;
	int		start;

	i = 0;
	str = malloc(sizeof(char *) * 3);
	str[2] = NULL;
	while (texture[i] == ' ')
		i++;
	start = i;
	while (texture[i] && texture[i] != ' ')
	{
		i++;
	}
	str[0] = ft_substr(texture, start, (i - start));
	str[1] = ft_substr(texture, i, ft_strlen(texture + i));
	return (str);
}

void	check_empty_line(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] > 32 && vars->map[i][j] <= 127)
				break ;
			else
				j++;
		}
		if (j == ft_strlen(vars->map[i]))
		{
			printf("error\n");
			exit(1);
		}
		i++;
	}
}

int	check_symbol(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 127)
			return (0);
		else
			break ;
		i++;
	}
	return (1);
}

void	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
		}
		i++;
	}
}
