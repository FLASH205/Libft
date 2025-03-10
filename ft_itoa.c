/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:36:29 by ybahmaz           #+#    #+#             */
/*   Updated: 2024/11/13 12:52:39 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_size(long int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	else if (n == 0)
		size = 1;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	unsigned int	nbr;

	size = count_size(n);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = '0';
	nbr = n;
	if (n < 0)
	{
		nbr = n * -1;
		str[0] = '-';
	}
	size -= 1;
	while (nbr > 0)
	{
		str[size] = nbr % 10 + '0';
		size--;
		nbr /= 10;
	}
	return (str);
}
