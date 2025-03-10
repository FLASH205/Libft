/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:22:04 by ybahmaz           #+#    #+#             */
/*   Updated: 2024/11/19 16:36:34 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_word(const char *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

int	count_w(char const *s, char c)
{
	int	count;
	int	nb;

	count = 0;
	nb = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			count = 1;
			nb++;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (nb);
}

void	ft_free(char **split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
}

int	ft_tret(char **split, const char *s, char c, int n)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	while (i < n)
	{
		k = 0;
		while (s[j] && s[j] == c)
			j++;
		str = (char *)malloc(len_word(s, j, c) + 1);
		if (!str)
		{
			ft_free(split, i);
			return (0);
		}
		while (s[j] && s[j] != c)
			str[k++] = s[j++];
		str[k] = '\0';
		split[i++] = str;
	}
	split[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		x;

	if (!s)
		return (0);
	x = count_w(s, c);
	split = (char **)malloc((x + 1) * sizeof(char *));
	if (!split)
		return (0);
	if (!ft_tret(split, s, c, x))
		return (0);
	return (split);
}
