/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:15:07 by ksaelim           #+#    #+#             */
/*   Updated: 2022/04/04 23:28:14 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	a_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*word_count(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, i + 1);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	ss = (char **)malloc((a_count(s, c) + 1) * sizeof(char *));
	if (!ss)
		return (NULL);
	i = 0;
	j = 0;
	while (i < a_count(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		ss[i] = word_count(&s[j], c);
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	ss[i] = NULL;
	return (ss);
}
