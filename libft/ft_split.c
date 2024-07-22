/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:17:10 by msoklova          #+#    #+#             */
/*   Updated: 2024/03/19 11:27:52 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	co;
	int	i;

	co = 0;
	i = 0;
	if (c == '\0')
		return (1);
	while (*s)
	{
		if (*s == c)
			i = 0;
		else if (i == 0)
		{
			co++;
			i = 1;
		}
		s++;
	}
	return (co);
}

static int	one_word(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char	**free_split(char **s, int i)
{
	while (i >= 0)
		free(s[i--]);
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i[3];
	char	**split;

	i[2] = 0;
	i[0] = 0;
	while (s[i[0]] == c && c)
		i[0]++;
	split = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (s[i[0]])
	{
		i[1] = 0;
		split[i[2]] = (char *)ft_calloc((one_word(&s[i[0]], c) + 1),
				sizeof(char));
		if (!split[i[2]])
			return (free_split(split, i[2]));
		while (s[i[0]] && s[i[0]] != c)
			split[i[2]][i[1]++] = s[i[0]++];
		split[i[2]][i[1]] = '\0';
		i[2]++;
		while (s[i[0]] && s[i[0]] == c)
			i[0]++;
	}
	return (split);
}
