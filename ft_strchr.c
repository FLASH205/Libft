/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:08:50 by ybahmaz           #+#    #+#             */
/*   Updated: 2024/11/20 09:05:22 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (char)c;
	if (ch == '\0')
	{
		i = ft_strlen(str);
		return (str + i);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
