/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cl9u <cl9u@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:44:04 by cl9u              #+#    #+#             */
/*   Updated: 2026/07/15 17:18:38 by cl9u             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len ++;
	}
	return (len);
}

int	ft_str_join_len(int size, char **strs, char *sep)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		if (i < size - 1)
			total += ft_strlen(sep);
		i++;
	}
	return (total);
}

void	ft_join_strs(char *dst, int *pos, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[*pos] = src[i];
		(*pos)++;
		i++;
	}
}

char	*ft_empty_str(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		pos;
	int		len;
	char	*str;

	if (size == 0)
	{
		return (ft_empty_str());
	}
	len = ft_str_join_len(size, strs, sep);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < size)
	{
		ft_join_strs(str, &pos, strs[i]);
		if (i < size - 1)
			ft_join_strs(str, &pos, sep);
		i++;
	}
	str[pos] = '\0';
	return (str);
}
