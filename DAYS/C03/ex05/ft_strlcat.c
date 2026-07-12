/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cl9u <cl9u@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 20:10:37 by cl9u              #+#    #+#             */
/*   Updated: 2026/07/12 20:25:35 by cl9u             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dln;
	unsigned int	sln;

	dln = 0;
	while (dest[dln])
		dln++;
	sln = 0;
	while (src[sln])
		sln++;
	if (size <= dln)
		return (dln + sln);
	i = 0;
	j = dln;
	while (src[i] && j < size - 1)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dln + sln);
}
