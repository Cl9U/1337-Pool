/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cl9u <cl9u@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:46:30 by cl9u              #+#    #+#             */
/*   Updated: 2026/07/15 19:07:16 by cl9u             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_base_len(char *base);

int	ft_count_digit(long nbr, int base_len)
{
	int	count;

	count = 1;
	while (nbr >= base_len)
	{
		nbr /= base_len;
		count++;
	}
	return (count);
}

char	*ft_fill_digits(char *res, long n, int len, char *base_to)
{
	int	base_len;

	base_len = ft_base_len(base_to);
	while (len > 0)
	{
		res[len - 1] = base_to[n % base_len];
		n /= base_len;
		len--;
	}
	return (res);
}

char	*ft_itoa_base(int nbr, char *base_to)
{
	long	n;
	int		base_len;
	int		len;
	int		s;
	char	*res;

	n = nbr;
	base_len = ft_base_len(base_to);
	s = (n < 0);
	if (s)
		n = -n;
	len = ft_count_digit(n, base_len);
	res = malloc(len + s + 1);
	if (!res)
		return (NULL);
	res[len + s] = '\0';
	if (s)
		res[0] = '-';
	ft_fill_digits(res + s, n, len, base_to);
	return (res);
}
