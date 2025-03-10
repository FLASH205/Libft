/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:42:49 by ybahmaz           #+#    #+#             */
/*   Updated: 2024/11/14 11:21:01 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	r;

	r = count * size;
	if (count && r / count != size)
		return (0);
	s = malloc(size * count);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size * count);
	return (s);
}
