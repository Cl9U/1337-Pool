/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cl9u <cl9u@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 16:39:02 by cl9u              #+#    #+#             */
/*   Updated: 2026/07/10 19:39:35 by cl9u             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
}

void	ft_next_comb(int *arr, int n)
{
	int	i;
	int	j;

	i = n - 1;
	while (i >= 0)
	{
		if (arr[i] < 9 - (n - 1 - i))
		{
			arr[i]++;
			j = i + 1;
			while (j < n)
			{
				arr[j] = arr[j - 1] + 1;
				j++;
			}
			break ;
		}
		i--;
	}
}

void	ft_comb(int *arr, int n)
{
	while (1)
	{
		ft_print_comb(arr, n);
		if (arr[0] == 10 - n)
			break ;
		write(1, ", ", 2);
		ft_next_comb(arr, n);
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	arr[10];

	if (n <= 0 || n > 10)
	{
		return ;
	}
	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	ft_comb(arr, n);
}
