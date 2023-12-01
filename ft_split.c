/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:16:31 by lohanyan          #+#    #+#             */
/*   Updated: 2023/04/14 17:19:55 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	size_t	i;
	size_t	skizb;
	size_t	avart;

	str = (char **)malloc ((ft_count(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (0);
	i = 0;
	skizb = 0;
	avart = 0;
	while (i < ft_count(s, c))
	{
		while (s[skizb] == c)
			skizb++;
		avart = skizb;
		while (s[avart] != c && s[avart])
			avart++;
		str[i] = ft_substr(s + skizb, 0, (avart - skizb));
		skizb = avart;
		i++;
	}
	str[i] = 0;
	return (str);
}
