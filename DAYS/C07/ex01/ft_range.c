/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cl9u <cl9u@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:53:15 by cl9u              #+#    #+#             */
/*   Updated: 2026/07/14 17:08:04 by cl9u             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	*arr;

	if (min >= max)
		return (NULL);
	i = max - min;
	arr = malloc(i * sizeof(int));
	if (!arr)
		return (NULL);
	j = 0;
	while (j < i)
	{
		arr[j] = min + j;
		j++;
	}
	return (arr);
}
