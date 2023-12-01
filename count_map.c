/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:58:51 by lohanyan          #+#    #+#             */
/*   Updated: 2023/05/18 15:17:01 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_map(int fd2)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = 0;
	while (1)
	{
		tmp = get_next_line(fd2);
		if (!ft_strlen(tmp))
			break ;
		i++;
		free(tmp);
		tmp = 0;
	}
	free(tmp);
	close(fd2);
	return (i);
}

void	free_double(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	(tmp) = NULL;
}

int	get_index_map(char	**map, int count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = count;
	count--;
	while (map && count != 0 && map[count])
	{
		j = -1;
		while (map[count][++j] != '\0')
		{
			if (map[count][j] != '1' && map[count][j] != '0'
					&& map[count][j] != ' ' && map[count][j] != 'N'
					&& map[count][j] != 'S' && map[count][j] != 'W'
					&& map[count][j] != 'E' && map[count][j] != '\n')
			{
				k = count;
				count = 1;
				break ;
			}
		}
		count--;
	}
	return (k);
}

void	print_error(t_addres *address, char *err, int flag)
{
	write(2, "Error!\n", 7);
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	if (flag == 1)
		free_all(address);
	exit(EXIT_FAILURE);
}

void	check_flag(int flag)
{
	if (flag == 0)
	{
		printf("none position\n");
		exit(1);
	}
}
