/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:38:52 by ybahmaz           #+#    #+#             */
/*   Updated: 2024/11/20 13:50:16 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	first;
	size_t	last;

	if (!s1)
		return (NULL);
	if (!set || !set[0])
		return (ft_strdup(s1));
	first = 0;
	last = ft_strlen(s1);
	while (check(set, s1[first]) == 1)
		first++;
	if (first == ft_strlen(s1))
		return (ft_strdup(""));
	while (check(set, s1[last - 1]) == 1)
		last--;
	str = ft_substr(s1, first, last - first);
	return (str);
}
