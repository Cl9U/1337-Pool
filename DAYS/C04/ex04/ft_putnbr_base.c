/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cl9u <cl9u@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:41:30 by cl9u              #+#    #+#             */
/*   Updated: 2026/07/13 13:42:25 by cl9u             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	n;

	if (!(ft_is_valid_base(base)))
		return ;
	n = nbr;
	len = ft_base_len(base);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= len)
		ft_putnbr_base(n / len, base);
	write(1, &base[n % len], 1);
}
